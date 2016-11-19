//
// Created by ahmad on 11/19/16.
//

#include "BST.h"
template <class type> BSTNode<type>::BSTNode()
{
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}
template <class type> BSTNode<type>::BSTNode(type &data)
{
    BSTNode();
    this->data = data;
}
template <class type> type BSTNode<type>::getData()
{
    return this->data;
}
//////////////////////////////////////////////
///  Function Implementaoin of BST class  ////
//////////////////////////////////////////////
template <class type> BST<type>::BST()
{
    this->root = nullptr;
}
template <class type> void BST<type>::add(type &data)
{
    BSTNode **pointer = &(this->root);
    while ((*pointer)){
        if(data > (*pointer)->getData()){
            (*pointer) = ((*pointer)->getLeftChild());
        } else{     //  data <= (*pointer)->getLeftChild()->getData()
            (*pointer) = ((*pointer)->getRightChild());
        }
    }
    (*pointer) = new BSTNode(data);
}

template <class type> BST<type>::~BST()
{
    // Todo design an algorithm to free the memory
}