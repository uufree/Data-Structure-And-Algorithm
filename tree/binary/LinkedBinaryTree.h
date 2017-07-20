/*************************************************************************
	> File Name: LinkedBinaryTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年05月24日 星期三 00时24分33秒
 ************************************************************************/

#ifndef _LINKEDBINARYTREE_H
#define _LINKEDBINARYTREE_H

#include<vector>
#include"BinaryTree.h"

class LinkedBinaryTree : public BinaryTree
{
    typedef std::function<void(BinaryTreeNode*)> CallBack;

    public:
        LinkedBinaryTree();
        LinkedBinaryTree(const LinkedBinaryTree& lhs);
        LinkedBinaryTree(LinkedBinaryTree&& lhs);
        LinkedBinaryTree& operator=(const LinkedBinaryTree& lhs);
        LinkedBinaryTree& operator=(LinkedBinaryTree&& lhs);
        ~LinkedBinaryTree();

        bool empty() const override
        {return theTreeSize == 0;};

        int size() const override
        {return theTreeSize;};
        
        int hight() const override
        {return theHigh;};
        
        void perOrder(const CallBack& cb) override
        {
            callback = cb;
            thePerOrder(boot);
        }
        
        void inOrder(const CallBack& cb) override
        {
            callback = cb;
            theInOrder(boot);
        }
        
        void postOrder(const CallBack& cb) override
        {
            callback = cb;
            thePostOrder(boot);
        }

        void levelOrder(const CallBack& cb) override
        {
            callback = cb;
            theLevelOrder(boot);
        }

        void init();
        int height();

    private:
        void thePerOrder(BinaryTreeNode* ptr);
        void theInOrder(BinaryTreeNode* ptr);
        void thePostOrder(BinaryTreeNode* ptr);
        void theLevelOrder(BinaryTreeNode* ptr);
        BinaryTreeNode* theCopy(BinaryTreeNode* ptr);
        int theHeight(BinaryTreeNode* node);
        

    private:
        BinaryTreeNode* boot;
        int theTreeSize;
        int theHigh;
        CallBack callback;
};

#endif
