/*************************************************************************
	> File Name: BinaryTreeNode.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月11日 星期一 16时30分32秒
 ************************************************************************/

#ifndef _BINARYTREENODE_H
#define _BINARYTREENODE_H

template<typename T>
struct BinaryTreeNode
{
    T element;
    BinaryTreeNode<T>* leftChild,*rightChild;

    BinaryTreeNode()
    {leftChild = rightChild = nullptr;};

    BinaryTreeNode(const T& theElement)
    {
        element = theElement;
        leftChild = rightChild = nullptr;
    }

    BinaryTreeNode(const BinaryTreeNode& lhs)
    {
        element = lhs.element;
        leftChild = lhs.leftChild;
        rightChild = lhs.rightChild;
    }
};

#endif
