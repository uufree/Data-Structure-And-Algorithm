/*************************************************************************
	> File Name: BinaryTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年05月24日 星期三 00时11分52秒
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include<functional>
#include<iostream>

struct BinaryTreeNode
{
    int data;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;

    BinaryTreeNode() : leftChild(nullptr),rightChild(nullptr)
    {};
    
    BinaryTreeNode(const int& data_) : data(data_),leftChild(nullptr),rightChild(nullptr)
    {};
};


class BinaryTree
{
    typedef std::function<void(BinaryTreeNode*)> CallBack;
    
    public:
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual int hight() const = 0; 
        virtual void perOrder(const CallBack& cb) = 0;
        virtual void inOrder(const CallBack& cb) = 0;
        virtual void postOrder(const CallBack& cb) = 0;
        virtual void levelOrder(const CallBack& cb) = 0;
};


#endif
