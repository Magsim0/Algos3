#pragma once
#include "Node.h"

class BinaryTree {
public:
    BinaryTree();
    ~BinaryTree();
    void insert(const double& value);
    bool search(const double& value) const;
    void printInOrder() const;
    int getHeight(Node* node) const; 
    Node* findMin(Node* node);
    Node* deleteNodeBST(Node* root, double key);
    Node* root;
    void breadthFirstTraversal() const;
    void Preorder() const;
    void Postorder() const;
    void Inorder() const;

private:
    
    Node* insertRecursive(Node* current, const double& value);
    bool searchRecursive(const Node* current, const double& value) const;
    void clear(Node* current);
    void PreorderTraversal(Node* current) const;
    void PostorderTraversal(Node* current) const;
    void InorderTraversal(Node* current) const;
};

