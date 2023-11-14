#include "red_black_tree.h"
#include"Node.h"
#include <iostream>

using namespace std;

RedBlackTree::RedBlackTree() : root(nullptr) {}

void RedBlackTree::insert(const double& value) {
    Node* node = new Node(value);
    root = insertRecursive(root, node);
    fixInsert(node);
}
int RedBlackTree::getHeight(Node* node) const {

    if (node == nullptr) {
        return 0;
    }

    // повторяем для левого и правого поддерева и учитываем максимальную глубину
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

void RedBlackTree::printInOrder() const {
    inOrderTraversal(root);
}

Node* RedBlackTree::insertRecursive(Node* current, Node* newNode) {
    if (current == nullptr) {
        return newNode;
    }

    if (newNode->data < current->data) {
        current->left = insertRecursive(current->left, newNode);
        current->left->parent = current;
    }
    else if (newNode->data > current->data) {
        current->right = insertRecursive(current->right, newNode);
        current->right->parent = current;
    }
   
    return current;
}


void RedBlackTree::fixInsert(Node* node) {
    while (node != root && node->parent != nullptr && node->parent->color == RED) {
        if (node->parent->parent != nullptr) {
            if ( node->parent == node->parent->parent->left) {
                Node* uncle = node->parent->parent->right;
                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->right) {
                        node = node->parent;
                        leftRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    rightRotate(node->parent->parent);
                }
            }
            else {
                Node* uncle = node->parent->parent->left;
                if (uncle != nullptr && uncle->color == RED) {
                    node->parent->color = BLACK;
                    uncle->color = BLACK;
                    node->parent->parent->color = RED;
                    node = node->parent->parent;
                }
                else {
                    if (node == node->parent->left) {
                        node = node->parent;
                        rightRotate(node);
                    }
                    node->parent->color = BLACK;
                    node->parent->parent->color = RED;
                    leftRotate(node->parent->parent);
                }
            }
        }
        else {
            root->color = BLACK;
            break;

        }

    }
   
    root->color = BLACK;
}

void RedBlackTree::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    }
    else if (x == x->parent->left) {
        x->parent->left = y;
    }
    else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RedBlackTree::rightRotate(Node* y) {
    Node* x = y->left;
    y->left = x->right;
    if (x->right != nullptr) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nullptr) {
        root = x;
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

Node* RedBlackTree::search(double key) const {
    return searchRecursive(root, key);
}

Node* RedBlackTree::searchRecursive(Node* current, double key) const {
    while (current != nullptr && key != current->data) {
        if (key < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return current;
}

Node* RedBlackTree::findMin(Node* node) {
    // Находим узел с минимальным значением в дереве (идем влево до конца)
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* RedBlackTree::findSuccessor(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->right != nullptr) {
        // Если у узла есть правое поддерево, находим минимальное значение в правом поддереве
        return findMin(node->right);
    }

    // Если у узла нет правого поддерева, ищем первый предок, у которого узел является левым потомком
    Node* successor = nullptr;
    Node* current = root;

    while (current != nullptr) {
        if (node->data < current->data) {
            successor = current;
            current = current->left;
        }
        else if (node->data > current->data) {
            current = current->right;
        }
        else {
            // Узел найден, выходим из цикла
            break;
        }
    }

    return successor;
}

void RedBlackTree::deleteNodeRedBlackTree(double key) {
    Node* node = search(key);
    if (node == nullptr) {
        return;  // Узел не найден
    }

    Node* successor;
    Node* child;

    if (node->left == nullptr || node->right == nullptr) {
        successor = node;
    }
    else {
        successor = findSuccessor(node);
    }

    if (successor->left != nullptr) {
        child = successor->left;
    }
    else {
        child = successor->right;
    }

    if (child != nullptr) {
        child->parent = successor->parent;
    }

    if (successor->parent == nullptr) {
        root = child;
    }
    else {
        if (successor == successor->parent->left) {
            successor->parent->left = child;
        }
        else {
            successor->parent->right = child;
        }
    }

    if (successor != node) {
        node->data = successor->data;
    }

    if (successor->color == BLACK) {
        fixDelete(this, child, successor->parent);  // Передаем указатель на текущий объект
    }

    delete successor;
}

void RedBlackTree::fixDelete(RedBlackTree* tree, Node* node, Node* parent) {
    Node* sibling = nullptr;

    while ((node == nullptr || node->color == BLACK) && node != tree->root) {
        if (node == parent->left) {
            sibling = parent->right;

            if (sibling != nullptr && sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                tree->leftRotate(parent);
                sibling = parent->right;
            }

            if ((sibling == nullptr || sibling->color == BLACK) &&
                (sibling == nullptr || sibling->color == BLACK)) {
                if (sibling != nullptr) {
                    sibling->color = RED;
                }
                node = parent;
                parent = node->parent;
            }
            else {
                if (sibling->right == nullptr || sibling->right->color == BLACK) {
                    if (sibling->left != nullptr) {
                        sibling->left->color = BLACK;
                    }
                    sibling->color = RED;
                    tree->rightRotate(sibling);
                    sibling = parent->right;
                }

                if (sibling != nullptr) {
                    sibling->color = parent->color;
                    parent->color = BLACK;
                    if (sibling->right != nullptr) {
                        sibling->right->color = BLACK;
                    }
                    tree->leftRotate(parent);
                }

                node = tree->root;
            }
        }
        else {
            sibling = parent->left;

            if (sibling != nullptr && sibling->color == RED) {
                sibling->color = BLACK;
                parent->color = RED;
                tree->rightRotate(parent);
                sibling = parent->left;
            }

            if ((sibling == nullptr || sibling->color == BLACK) &&
                (sibling == nullptr || sibling->color == BLACK)) {
                if (sibling != nullptr) {
                    sibling->color = RED;
                }
                node = parent;
                parent = node->parent;
            }
            else {
                if (sibling->left == nullptr || sibling->left->color == BLACK) {
                    if (sibling->right != nullptr) {
                        sibling->right->color = BLACK;
                    }
                    sibling->color = RED;
                    tree->leftRotate(sibling);
                    sibling = parent->left;
                }

                if (sibling != nullptr) {
                    sibling->color = parent->color;
                    parent->color = BLACK;
                    if (sibling->left != nullptr) {
                        sibling->left->color = BLACK;
                    }
                    tree->rightRotate(parent);
                }

                node = tree->root;
            }
        }
    }

    if (node != nullptr) {
        node->color = BLACK;
    }
}

