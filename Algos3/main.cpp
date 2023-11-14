#include "red_black_tree.h"
#include "binary_tree.h"
#include "avl_tree.h"
#include <iostream>
#include <chrono>
#include <random>
#include <fstream>


using namespace std;

template<typename TreeType>
void insertValues(TreeType& tree, const double* values, int dataSize) {
    
    for (int i = 0; i < dataSize; ++i) {
        
        tree.insert(values[i]);
    }
}

void measureRedBlackTreeDeletion(int dataSize, ofstream& fout) {
    RedBlackTree redBlackTree;

    // Вставка элементов в красно-черное дерево
    for (int i = 0; i < dataSize; ++i) {
        redBlackTree.insert(i);
    }

    auto start = chrono::high_resolution_clock::now();

    // Удаление элементов из красно-черного дерева
    for (int i = 0; i < dataSize; ++i) {
        redBlackTree.deleteNodeRedBlackTree(i);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    fout << "Red-Black Tree Deletion Time for " << dataSize << " elements: " << duration.count() << " seconds" << std::endl;
}

void measureAVLTreeDeletion(int dataSize, ofstream& fout) {
    AVLTree avlTree;

    // Вставка элементов в AVL-дерево
    for (int i = 0; i < dataSize; ++i) {
        avlTree.insert(i);
    }

    auto start = chrono::high_resolution_clock::now();

    // Удаление элементов из AVL-дерева
    for (int i = 0; i < dataSize; ++i) {
        avlTree.deleteNode(i);
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    fout << "AVL Tree Deletion Time for " << dataSize << " elements: " << duration.count() << " seconds" << std::endl;
}

int main() {
    ofstream fout("output_time.txt");
    
    

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    BinaryTree binaryTree;
    AVLTree avlTree;
    RedBlackTree redBlackTree;

    const int dataSize = 20000;
    double values[dataSize];
    for (int i = 0; i < dataSize; ++i) {
        values[i] = rand() % 1000 / 10.0; 
    }
    //------Время балансировки ВСТАВКА ----------
    insertValues(binaryTree, values, dataSize);


    fout << "AVL" << endl;
    auto startAvl = chrono::high_resolution_clock::now();
    insertValues(avlTree, values, dataSize);
    auto endAvl = chrono::high_resolution_clock::now();
    chrono::duration<double> durationInsertAvlTree = endAvl - startAvl;
    fout << "Insert time for AVL Tree: " << durationInsertAvlTree.count() << " seconds" << endl;

    fout << "RB" << endl;
    auto startRB = chrono::high_resolution_clock::now();
    insertValues(redBlackTree, values, dataSize);
    auto endRB = chrono::high_resolution_clock::now();
    chrono::duration<double> durationInsertRBTree = endRB - startRB;
    fout << "Insert time for Red-Black Tree: " << durationInsertRBTree.count() << " seconds" << endl;

    //-------высоты деревьев---------
    cout << "Number of elements = " << dataSize << endl;
   cout << "Binary Tree Height: " << binaryTree.getHeight(binaryTree.root) << endl;
   // binaryTree.printInOrder(); cout << endl;//------------------------------------------------------------ Посмотреть эл-ты дерева
   cout << "AVL Tree Height: " << avlTree.getHeight(avlTree.root) << endl;
   // avlTree.printInOrder(); cout << endl; //------------------------------------------------------------ Посмотреть эл-ты дерева
   cout << "Red-Black Tree Height: " << redBlackTree.getHeight(redBlackTree.root) <<endl;
    //redBlackTree.printInOrder(); cout << endl; //------------------------------------------------------------ Посмотреть эл-ты дерева
    

    //------Время балансировки УДАЛЕНИЕ ----------

    measureRedBlackTreeDeletion(dataSize, fout);
    measureAVLTreeDeletion(dataSize, fout);

    //----------------------------------------------

   /* std::cout << "AVL Tree Pre-Order Traversal: ";
    avlTree.preOrderTraversal();
    std::cout << std::endl;

    std::cout << "Red-Black Tree Post-Order Traversal: ";
    redBlackTree.postOrderTraversal();
    std::cout << std::endl;*/
        return 0;
    }