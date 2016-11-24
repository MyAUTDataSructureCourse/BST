//
// Created by ahmad on 11/19/16.
//

#include "BST.h"
//////////////////////////////////////////////////
///  Function Implementaoin of BSTNode class  ////
//////////////////////////////////////////////////

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
template <class type> type BSTNode<type>::getData() { return this->data; }

template <class type> void BSTNode<type>::setLeftChild(BSTNode<type> *lc) {}
template <class type> void BSTNode<type>::setRightChild(BSTNode<type> *rc) {}
template <class type> void BSTNode<type>::setData(type &data) {}
template <class type> BSTNode<type> *BSTNode<type>::getLeftChild(){}
template <class type> BSTNode<type> *BSTNode<type>::getRightChild(){}
template <class type> type *BSTNode<type>::getData(type *dataPointer){}
//////////////////////////////////////////////
///  Function Implementaoin of BST class  ////
//////////////////////////////////////////////
template <class type> BST<type>::BST()
{
    this->root = nullptr;
}
template <class type> void BST<type>::add(type &data)
{
    BSTNode<type> **pointer = &(this->root);
    while ((*pointer)){
        if(data > (*pointer)->getData()){
            (*pointer) = ((*pointer)->getLeftChild());
        } else{     //  data <= (*pointer)->getLeftChild()->getData()
            (*pointer) = ((*pointer)->getRightChild());
        }
    }
    (*pointer) = new BSTNode<type>(data);
}

template <class type> BST<type>::~BST()
{
    // Todo design an algorithm to free the memory
}
template <class type> void BST<type>::printPreOrder() {}
template <class type> void BST<type>::printInOrder() {}
template <class type> void BST<type>::printPostOrder() {}
template <class type> void BST<type>::printPreOrder(BSTNode<type> *root){}
template <class type> void BST<type>::printInOrder(BSTNode<type> *root){}
template <class type> void BST<type>::printPostOrder(BSTNode<type> *root){}