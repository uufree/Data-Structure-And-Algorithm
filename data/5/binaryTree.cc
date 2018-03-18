/*************************************************************************
	> File Name: binaryTree.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时04分31秒
 ************************************************************************/

#include<iostream>
#include"binaryTree.h"

template<typename T>
inline bool IsRoot(BinaryNode<T> const* node)
{return !node->_parent;}

template<typename T>
inline bool IsLeftChild(BinaryNode<T> const* node)
{return !(IsRoot(node)) & (node == node->_parent->_leftChild);}

template<typename T>
inline bool IsRightChild(BinaryNode<T> const* node)
{return !(IsRoot(node)) & (node == node->_parent->_rightChild);}

template<typename T>
inline bool HasParent(BinaryNode<T> const* node)
{return !(IsRoot(node));}

template<typename T>
inline bool HasLeftChild(BinaryNode<T> const* node)
{return node->_leftChild;}

template<typename T>
inline bool HasRightChild(BinaryNode<T> const* node)
{return node->_rightChild;}

template<typename T>
inline bool HasChild(BinaryNode<T> const* node)
{return HasLeftChild(node) || HasRightChild(node);}

template<typename T>
inline bool HasBothChild(BinaryNode<T> const* node)
{return HasLeftChild(node) & HasRightChild(node);}

template<typename T>
inline bool IsLeaf(BinaryNode<T> const* node)
{return !(HasChild(node));}

template<typename T>
inline BinaryNode<T>* Brother(BinaryNode<T> const* node)
{return IsLeftChild(node) ? node->_parent->_rightChild : node->_parent->_leftChild;}

template<typename T>
inline BinaryNode<T>* Uncle(BinaryNode<T> const* node)
{return IsLeftChild(node) ? node->_parent->_parent->_rightChild : node->_parent->_parent->_leftChild;}

template<typename T>
inline BinaryNode<T>* FromParentToRef(BinaryNode<T> const* node)
{return IsRoot(node) ? node : (IsLeftChild(node) ? node->_parent->_leftChild : node->_parent->_rightChild);}

template<typename T>
BinaryNode<T>* BinaryNode<T>::insertAsLeftChild(T const& elem)
{return _leftChild = new BinaryNode(elem,this);}

template<typename T>
BinaryNode<T>* BinaryNode<T>::insertAsRightChild(T const& elem)
{return _rightChild = new BinaryNode(elem,this);}





























