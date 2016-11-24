//
// Created by ahmad on 11/19/16.
//

#ifndef BST_BST_H
#define BST_BST_H

#define nullptr 0

template <class type> class BSTNode
{
public:
    BSTNode();
    BSTNode(type &data);

    void setLeftChild(BSTNode *lc);
    void setRightChild(BSTNode *rc);
    void setData(type &data);

    BSTNode *getLeftChild();
    BSTNode *getRightChild();
    type *getData(type *dataPointer);

    type getData();
private:
    type data;
    BSTNode *leftChild;
    BSTNode *rightChild;
};

template <class type> class BST
{
private:
    BSTNode<type> *root;

    void printPreOrder(BSTNode<type> *root);
    void printInOrder(BSTNode<type> *root);
    void printPostOrder(BSTNode<type> *root);

public:
    BST();

    void add(type &data);
    void printPreOrder();
    void printInOrder();
    void printPostOrder();

    ~BST();
};

#endif //BST_BST_H
