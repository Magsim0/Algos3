#pragma once
#include "Node.h"
class RedBlackTree {
public:
    RedBlackTree();
    void insert(const double& value);
    void printInOrder() const;
    int getHeight(Node* node) const;
    Node* findSuccessor(Node* node);
    Node* search(double key) const;
    Node* searchRecursive(Node* current, double key) const;
    Node* root;
    Node* findMin(Node* node);

    void deleteNodeRedBlackTree(double key);
    void fixDelete(RedBlackTree* tree, Node* node, Node* parent);

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
    void fixInsert(Node* node);
    void leftRotate(Node* x);
    void rightRotate(Node* y);
};

