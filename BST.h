//
// Created by ahmad on 11/19/16.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <ostream>

#define nullptr 0

/**
 * For controlling whether which implementation(recursive or non) be used in code
 */
#define BST_ADD_RECURSIVE_IMPLEMENTATION
#define BST_TRAVERSAL_RECURSIVE_IMPLEMENTATION


template <class type> struct BSTNode
{
public:
    BSTNode();
    BSTNode(type &data);

    type data;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

template <class type> class BST
{
private:
    BSTNode<type> *root;

    void printPreOrder(BSTNode<type> *root, std::ostream &cout);
    void printInOrder(BSTNode<type> *root, std::ostream &cout);
    void printPostOrder(BSTNode<type> *root, std::ostream &cout);
    void addHelper(BSTNode<type> *root, BSTNode<type> *node);
    void deleteTree(BSTNode<type> *root);

public:
    BST();

    void add(type data);
    void printPreOrder(std::ostream &cout);
    void printInOrder(std::ostream &cout);
    void printPostOrder(std::ostream &cout);

    ~BST();
};

#include "BST.cpp"

#endif //BST_BST_H
