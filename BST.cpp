//
// Created by ahmad on 11/19/16.
//

#include "BST.h"

#ifndef BST_TRAVERSAL_RECURSIVE_IMPLEMENTATION
#include <stack>
#endif

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
            } else if(data <= pointer->data){
                pointer = (pointer->leftChild);
            }else{
                // TODO something for handling if two nodes have equal data
                std::cout << "Some wrong has happened" << std::endl;
                return;
            }
        }
        if(data <= parent->data){
            parent->leftChild = newNode;
        } else if(data > parent->data) {
            parent->rightChild = newNode;
        }
    } else{
        this->root = newNode;
    }
#endif
}
template <class type> void BST<type>::deleteTree(BSTNode<type> *root)
{
    if (root == nullptr)
        return;

    deleteTree(root->leftChild);
    deleteTree(root->rightChild);
    delete root;
}
template <class type> BST<type>::~BST()
{
    deleteTree(this->root);
}
template <class type> void BST<type>::printPreOrder(std::ostream &cout)
{
#ifdef BST_TRAVERSAL_RECURSIVE_IMPLEMENTATION
    this->printPreOrder(this->root, cout);
#else
    std::stack<BSTNode <type>*> nodeStack;

    if (this->root)
    {
        nodeStack.push(this->root);

        while (! nodeStack.empty())
        {
            BSTNode<type> *node = nodeStack.top();
            cout << node->data << "\n";
            nodeStack.pop();

            if(node->rightChild) nodeStack.push(node->rightChild);
            if(node->leftChild) nodeStack.push(node->leftChild);
        }
    }
#endif
}
template <class type> void BST<type>::printInOrder(std::ostream &cout)
{
#ifdef BST_TRAVERSAL_RECURSIVE_IMPLEMENTATION
    this->printInOrder(this->root, cout);
#else
    std::stack<BSTNode <type>*> nodeStack;
    BSTNode<type> *node = this->root;

    while(true)
    {
        if(node)
        {
            nodeStack.push(node);
            node = node->leftChild;
        }
        else
        {
            if (!nodeStack.empty())
            {
                node = nodeStack.top();
                cout << node->data << "\n";
                nodeStack.pop();
                node = node->rightChild;
            }
            else
            {
                // Stack is empty and there is no pointer to travers so it's done
                break;
            }
        }
    }
#endif
}
template <class type> void BST<type>::printPostOrder(std::ostream &cout)
{
#ifdef BST_TRAVERSAL_RECURSIVE_IMPLEMENTATION
    this->printPostOrder(this->root, cout);
#else
    if(!this->root)
        return;

    std::stack<BSTNode <type>*> nodeStack;
    nodeStack.push(this->root);

    BSTNode <type> *prev = nullptr;

    while (!nodeStack.empty())
    {
        BSTNode <type> *current = nodeStack.top();
        if(!prev || prev->leftChild == current || prev->rightChild == current)
        {
            if (current->leftChild)
                nodeStack.push(current->leftChild);
            else if (current->rightChild)
                nodeStack.push(current->rightChild);
        }
        else if (current->leftChild == prev)
        {
            if (current->rightChild)
                nodeStack.push(current->rightChild);
        } else{
            cout << current->data << "\n";
            nodeStack.pop();
        }

        prev = current;
    }
#endif
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