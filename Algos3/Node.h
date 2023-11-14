#pragma once
enum Color{ RED, BLACK };

struct Node {
    double data;
    Node* left;
    Node* right;
    Node* parent;
    Color color;
    int height;

    Node(double val, Color nodeColor = RED)
        : data(val), left(nullptr), right(nullptr), parent(nullptr), color(nodeColor), height(1) {}
};