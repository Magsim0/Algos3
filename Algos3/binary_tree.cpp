#include <iostream>
#include "Node.h"
#include "binary_tree.h"

using namespace std;
BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    clear(root);
}

int BinaryTree::getHeight(Node* node) const {

    if (node == nullptr) {
        return 0;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

void BinaryTree::insert(const double& value) {
    root = insertRecursive(root, value);
}

bool BinaryTree::search(const double& value) const {
    return searchRecursive(root, value);
}

void BinaryTree::printInOrder() const {
    inOrderTraversal(root);
}

Node* BinaryTree::insertRecursive(Node* current, const double& value) {
    if (current == nullptr) {
        return new Node(value);
    }

    if (value < current->data) {
        current->left = insertRecursive(current->left, value);
    }
    else if (value > current->data) {
        current->right = insertRecursive(current->right, value);
    }

    return current;
}

bool BinaryTree::searchRecursive(const Node* current, const double& value) const {
    if (current == nullptr) {
        return false;
    }

    if (value == current->data) {
        return true;
    }
    else if (value < current->data) {
        return searchRecursive(current->left, value);
    }
    else {
        return searchRecursive(current->right, value);
    }
}

void BinaryTree::inOrderTraversal(const Node* current) const {
    if (current != nullptr) {
        inOrderTraversal(current->left);
        std::cout << current->data << " ";
        inOrderTraversal(current->right);
    }
}

void BinaryTree::clear(Node* current) {
    if (current != nullptr) {
        clear(current->left);
        clear(current->right);
        delete current;
    }
}

Node* BinaryTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BinaryTree::deleteNodeBST(Node* root, double key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNodeBST(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNodeBST(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNodeBST(root->right, temp->data);
    }

    return root;
}