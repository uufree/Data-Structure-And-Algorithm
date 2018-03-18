/*************************************************************************
	> File Name: binaryTree.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时04分31秒
 ************************************************************************/

#include<iostream>
#include"binaryTree.h"

template<typename T>
inline bool IsRoot(BinaryNode<T>& node)
{return !node._parent;}

template<typename T>
inline bool IsLeftChild(const BinaryNode<T>& node)
{return !(IsRoot(node)) & (node == node._parent->_leftChild);}

template<typename T>
inline bool IsRightChild(const BinaryNode<T>& node)
{return !(IsRoot(node)) & (node == node._parent->_rightChild);}

template<typename T>
inline bool HasParent(const BinaryNode<T>& node)
{return !(IsRoot(node));}

template<typename T>
inline bool 
