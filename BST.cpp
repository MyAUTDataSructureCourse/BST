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



  //////////////////////////////////////////////////////////////////////////////////////////////
 /////////////////////////////////  Function Implementaoin of BST class  //////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

/**
 * If want to add the nodes to the tree with recursive implementation
 * @tparam type
 */
//#define BST_ADD_RECURSIVE_IMPLEMENTATION

template <class type> BST<type>::BST()
{
    this->root = nullptr;
}

template <class type> void BST<type>::addHelper(BSTNode<type> *root, BSTNode<type> *node)
{
    if(root->data > node->data){
        if (root->leftChild)
            addHelper(root->leftChild,node);
        else
            root->leftChild = node;
    } else{
        if (root->rightChild)
            addHelper(root->rightChild,node);
        else
            root->rightChild = node;
    }
}
template <class type> void BST<type>::add(type data)
{
    BSTNode<type> *newNode = new BSTNode<type>(data);
    newNode->leftChild = nullptr;
    newNode->rightChild = nullptr;

#ifdef BST_ADD_RECURSIVE_IMPLEMENTATION
    if(root)
        addHelper(root, newNode);
    else
        root = newNode;
#endif

#ifndef BST_ADD_RECURSIVE_IMPLEMENTATION
    if(this->root){
        BSTNode<type> *parent = nullptr;
        BSTNode<type> *pointer = this->root;
        while (pointer){
            parent = pointer;
            if(data > pointer->data){
                pointer = (pointer->rightChild);
            } else if(data < pointer->data){
                pointer = (pointer->leftChild);
            }else{
                // TODO something for handling if two nodes have equal data
                std::cout << "Some wrong has happened" << std::endl;
                return;
            }
        }
        if(data < parent->data){
            parent->leftChild = newNode;
        } else if(data > parent->data) {
            parent->rightChild = newNode;
        }
    } else{
        this->root = newNode;
    }
#endif
}

template <class type> BST<type>::~BST()
{
    // Todo design an algorithm to free the memory
}
template <class type> void BST<type>::printPreOrder(std::ostream &cout)
{
    this->printPreOrder(this->root, cout);
}
template <class type> void BST<type>::printInOrder(std::ostream &cout)
{
    this->printInOrder(this->root, cout);
}
template <class type> void BST<type>::printPostOrder(std::ostream &cout)
{
    this->printPostOrder(this->root, cout);
}
template <class type> void BST<type>::printPreOrder(BSTNode<type> *root, std::ostream &cout)
{
    if(root == nullptr)
        return;
    cout << root->data << std::endl;
    this->printPreOrder(root->leftChild, cout);
    this->printPreOrder(root->rightChild, cout);
}
template <class type> void BST<type>::printInOrder(BSTNode<type> *root, std::ostream &cout)
{
    if(root == nullptr)
        return;
    this->printInOrder(root->leftChild, cout);
    cout << root->data << std::endl;
    this->printInOrder(root->rightChild, cout);
}
template <class type> void BST<type>::printPostOrder(BSTNode<type> *root, std::ostream &cout)
{
    if(root == nullptr)
        return;
    this->printPostOrder(root->leftChild, cout);
    this->printPostOrder(root->rightChild, cout);
    cout << root->data << std::endl;
}