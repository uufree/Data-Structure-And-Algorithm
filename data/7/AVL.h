/*************************************************************************
	> File Name: AVL.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月19日 星期一 19时36分20秒
 ************************************************************************/

#ifndef _AVL_H
#define _AVL_H

#include"binarySearchTree.h"

template<typename T>
class AVL : public BinarySearchTree<T>
{
    public:
        BinaryNode<T>* insert(T const& elem) override;
        bool remove(T const& elem) override;
};

template<typename T>
inline bool Balanced(BinaryNode<T> const* node)
{return Height(node->_leftChild) == Height(node->_rightChild);}

template<typename T>
inline int BalancedFactor(BinaryNode<T> const* node)
{return Height(node->_leftChild) - Height(node->_rightChild);}

template<typename T>
inline bool AVLBalanced(BinaryNode<T> const* node)
{return BalancedFactor(node) > -2 & BalancedFactor(node) < 2;};

template<typename T>
BinaryNode<T>*& TallerInChild(BinaryNode<T> const* node)
{
    return Height(node->_leftChild) > Height(node->_rightChild) ? node->_leftChild : Height(node->_rightChild) > Height(node->_leftChild) ? node->_rightChild : IsLeftChild(node) ? node->_leftChild : node->_rightChild;
}

template<typename T>
BinaryNode<T>* AVL<T>::insert(T const& elem)
{
    BinaryNode<T>*& node = search(elem);
    if(node)
        return node;
    BinaryNode<T>* newNode = new BinaryNode<T>(elem,BinarySearchTree<T>::_hot);
    ++BinaryTree<T>::_size;

    for(BinaryNode<T>* g_node = BinarySearchTree<T>::_hot;g_node;g_node=g_node->_parent)
    {
        if(!AVLBalanced(node))
        {
            FromParentToRef(g_node) = rotateAt(TallerInChild(g_node));
            break;
        }
        else
            updateHeightAbove(g_node);
    }
    return newNode;
}

template<typename T>
bool AVL<T>::remove(T const& elem)
{
    BinaryNode<T>*& node = search(elem);
    if(!node)
        return false;
    removeAt(node);
    --BinaryTree<T>::_size;
    
    for(BinaryNode<T>* g_node = BinarySearchTree<T>::_hot;g_node;g_node = g_node->_parent)
    {
        if(!AVLBalanced(g_node))
            FromParentToRef(g_node) = rotateAt(TallerInChild(g_node));
        else
            updateHeightAbove(g_node);
    }
    return true;
}

#endif
