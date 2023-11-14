#pragma once
#include "Node.h"
class AVLTree {
public:
    AVLTree();
    void insert(const double& value);
    void printInOrder() const; 
    int getHeight(Node* node) const;
    Node* root;
    Node* findMin(Node* node) const;
    Node* deleteNode(double key, Node* current);
    void deleteNode(double key);


    void breadthFirstTraversal() const;
    void preOrderTraversal() const;
    void postOrderTraversal() const;
    void inOrderTraversal() const;

private:
    
    void breadthFirstTraversal(Node* root) const;
    void preOrderTraversal(Node* root) const;
    void postOrderTraversal(Node* root) const;
    void inOrderTraversal(Node* root) const;

    Node* insertRecursive(Node* current, Node* newNode);

  
    int getBalanceFactor(Node* node) const;
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
};