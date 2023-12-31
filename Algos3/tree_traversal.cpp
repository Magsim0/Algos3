#include <iostream>
#include <queue> 
#include <stack> 
#include "red_black_tree.h"
#include "binary_tree.h"
#include "avl_tree.h"


void BinaryTree::breadthFirstTraversal() const {
    if (root == nullptr) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }

        if (current->right != nullptr) {
            q.push(current->right);
        }
    }

    std::cout << std::endl;
}

void BinaryTree::Preorder() const {
    PreorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::Postorder() const {
    PostorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::Inorder() const {
    InorderTraversal(root);
    std::cout << std::endl;
}

void BinaryTree::PreorderTraversal(Node* current) const {
    if (current == nullptr) return;

    std::cout << current->data << " ";
    PreorderTraversal(current->left);
    PreorderTraversal(current->right);
}

void BinaryTree::PostorderTraversal(Node* current) const {
    if (current == nullptr) return;

    PostorderTraversal(current->left);
    PostorderTraversal(current->right);
    std::cout << current->data << " ";
}

void BinaryTree::InorderTraversal(Node* current) const {
    if (current == nullptr) return;

    InorderTraversal(current->left);
    std::cout << current->data << " ";
    InorderTraversal(current->right);
}


void AVLTree::breadthFirstTraversal() const {
    breadthFirstTraversal(root);
}

void AVLTree::preOrderTraversal() const {
    preOrderTraversal(root);
}

void AVLTree::postOrderTraversal() const {
    postOrderTraversal(root);
}

void AVLTree::inOrderTraversal() const {
    inOrderTraversal(root);
}

void AVLTree::breadthFirstTraversal(Node* root) const {
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

void AVLTree::preOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void AVLTree::postOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

void AVLTree::inOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}



void RedBlackTree::breadthFirstTraversal() const {
    breadthFirstTraversal(root);
}

void RedBlackTree::preOrderTraversal() const {
    preOrderTraversal(root);
}

void RedBlackTree::postOrderTraversal() const {
    postOrderTraversal(root);
}

void RedBlackTree::inOrderTraversal() const {
    inOrderTraversal(root);
}

void RedBlackTree::breadthFirstTraversal(Node* root) const {
    if (root == nullptr)
        return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

void RedBlackTree::preOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void RedBlackTree::postOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

void RedBlackTree::inOrderTraversal(Node* root) const {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}