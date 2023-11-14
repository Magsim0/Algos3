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

    // ����� � ������
    void breadthFirstTraversal() const;

    // ����� � �������: ������ (preorder), �������� (postorder), ������������ (inorder)
    void depthFirstPreorder() const;
    void depthFirstPostorder() const;
    void depthFirstInorder() const;

private:
    
    Node* insertRecursive(Node* current, const double& value);
    
    bool searchRecursive(const Node* current, const double& value) const;
    void inOrderTraversal(const Node* current) const;
    void clear(Node* current);


    // ��������������� ������� ��� ����������� �������
    void depthFirstPreorderRecursive(Node* current) const;
    void depthFirstPostorderRecursive(Node* current) const;
    void depthFirstInorderRecursive(Node* current) const;
};

