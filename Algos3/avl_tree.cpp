#include "avl_tree.h"
#include <iostream>


AVLTree::AVLTree() : root(nullptr) {}

void AVLTree::insert(const double& value) {
    Node* node = new Node(value);
    root = insertRecursive(root, node);
}

void AVLTree::printInOrder() const {
    inOrderTraversal(root);
}

Node* AVLTree::insertRecursive(Node* current, Node* newNode) {
    if (current == nullptr) {
        return newNode;
    }

    if (newNode->data < current->data) {
        current->left = insertRecursive(current->left, newNode);
    }
    else if (newNode->data > current->data) {
        current->right = insertRecursive(current->right, newNode);
    }
    else {
        // Duplicate values are not allowed
        delete newNode;
        return current;
    }

    current->height = std::max(getHeight(current->left), getHeight(current->right)) + 1;
    return balance(current);
}


int AVLTree::getHeight(Node* node) const {
    return (node != nullptr) ? node->height : 0;
}

int AVLTree::getBalanceFactor(Node* node) const {
    return (node != nullptr) ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* AVLTree::balance(Node* node) {
    if (node == nullptr) {
        return nullptr;
    }

    int balance = getBalanceFactor(node);

    // Left Heavy
    if (balance > 1) {
        if (node->data > node->left->data) {
            return rotateRight(node);
        }
        else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (node->data < node->right->data) {
            return rotateLeft(node);
        }
        else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}
Node* AVLTree::findMin(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}

Node* AVLTree::deleteNode(double key, Node* current) {
    if (current == nullptr) {
        return current;
    }

    if (key < current->data) {
        current->left = deleteNode(key, current->left);
    }
    else if (key > current->data) {
        current->right = deleteNode(key, current->right);
    }
    else {
        if (current->left == nullptr || current->right == nullptr) {
            Node* temp = (current->left != nullptr) ? current->left : current->right;

            if (temp == nullptr) {
                temp = current;
                current = nullptr;
            }
            else {
                *current = *temp;
            }

            delete temp;
        }
        else {
            Node* temp = findMin(current->right);
            current->data = temp->data;
            current->right = deleteNode(temp->data, current->right);
        }
    }

    if (current == nullptr) {
        return current;
    }

    current->height = 1 + std::max(getHeight(current->left), getHeight(current->right));

    int balance = getBalanceFactor(current);

    if (balance > 1 && getBalanceFactor(current->left) >= 0) {
        return rotateRight(current);
    }

    if (balance > 1 && getBalanceFactor(current->left) < 0) {
        current->left = rotateLeft(current->left);
        return rotateRight(current);
    }

    if (balance < -1 && getBalanceFactor(current->right) <= 0) {
        return rotateLeft(current);
    }

    if (balance < -1 && getBalanceFactor(current->right) > 0) {
        current->right = rotateRight(current->right);
        return rotateLeft(current);
    }

    return current;
}

void AVLTree::deleteNode(double key) {
    root = deleteNode(key, root);
}