/*************************************************************************
	> File Name: binaryTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时03分39秒
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include<iostream>

typedef enum{RB_RED,RB_BLACK} RBColor;
/*
#define IsRoot(node) (!((node)._parent))
#define IsLeftChild(node) ((!IsRoot(node)) & ((node) == ((node)._parent)->_leftChild))
#define IsRightChild(node) ((!IsRoot(node)) & ((node) == ((node)._parent)->_rightChild))
#define HasParent(node) (!IsRoot(node))
#define HasLeftChild(node) ((node)._leftChild)
#define HasRightChild(node) ((node)._rightChild)
#define HasChild(node) (HasLeftChild(node) || HasRightChild(node))
#define HasBothChild(node) (HasLeftChild(node) & HasRightChild(node))
#define IsLeaf(node) (!HasChild(node))
*/

template<typename T>
struct BinaryNode
{
    T _data;
    BinaryNode<T>* _parent;
    BinaryNode<T>* _leftChild;
    BinaryNode<T>* _rightChild;
    int _hight;
    RBColor _color;

    BinaryNode() : 
        _data(T()),
        _parent(NULL),
        _leftChild(NULL),
        _rightChild(NULL),
        _hight(0),
        _color(RB_RED)
    {};

    BinaryNode(T data,BinaryNode<T>* parent = NULL,BinaryNode<T>* leftChild = NULL,BinaryNode<T>* rightChild = NULL,int hight = 0,RBColor color = RB_RED) :
        _data(data),
        _parent(parent),
        _leftChild(leftChild),
        _rightChild(rightChild),
        _hight(hight),
        _color(color)
    {};

    int size();
    BinaryNode<T>* insertAsLeftChild(T const& data);
    BinaryNode<T>* insertAsRightChild(T const& data);
    BinaryNode<T>* succ();//取当前节点的直接后继
    void travLevel();
    void travPre();
    void travIn();
    void travPost();

    bool operator==(BinaryNode const& node){return node._data == _data;};
    bool operator<(BinaryNode const& node){return _data < node._data;};
};


#endif
