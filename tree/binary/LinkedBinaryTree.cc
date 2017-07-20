/*************************************************************************
	> File Name: LinkedBinaryTree.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年05月24日 星期三 00时57分36秒
 ************************************************************************/

#include"LinkedBinaryTree.h"
#include<deque>
#include<cmath>

LinkedBinaryTree::LinkedBinaryTree() : 
    boot(nullptr),   
    theTreeSize(0),
    theHigh(0)
{};

LinkedBinaryTree::LinkedBinaryTree(const LinkedBinaryTree& lhs) : 
    theTreeSize(lhs.theTreeSize),
    theHigh(lhs.theHigh)
{
    boot = theCopy(lhs.boot);
}

LinkedBinaryTree::LinkedBinaryTree(LinkedBinaryTree&& lhs) :   
    boot(std::move(lhs.boot)),
    theTreeSize(lhs.theTreeSize),
    theHigh(lhs.theHigh)
{}

LinkedBinaryTree& LinkedBinaryTree::operator=(const LinkedBinaryTree& lhs)
{
    postOrder([this](BinaryTreeNode* ptr){delete ptr;});
    theTreeSize = lhs.theTreeSize;
    theHigh = lhs.theHigh;
    boot = theCopy(lhs.boot);

    return *this;
}

LinkedBinaryTree& LinkedBinaryTree::operator=(LinkedBinaryTree&& lhs)
{
    postOrder([this](BinaryTreeNode* ptr){delete ptr;});
    theTreeSize = lhs.theTreeSize;
    theHigh = lhs.theHigh;
    boot = std::move(lhs.boot);

    return *this;
}

LinkedBinaryTree::~LinkedBinaryTree()
{
    postOrder([this](BinaryTreeNode* ptr){delete ptr;});
}


void LinkedBinaryTree::thePerOrder(BinaryTreeNode* ptr)
{
    if(ptr != nullptr)
    {
        callback(ptr);
        thePerOrder(ptr->leftChild);
        thePerOrder(ptr->rightChild);
    }
}

void LinkedBinaryTree::theInOrder(BinaryTreeNode* ptr)
{
    if(ptr != nullptr)
    {
        theInOrder(ptr->leftChild);
        callback(ptr);
        theInOrder(ptr->rightChild);
    }
}

void LinkedBinaryTree::thePostOrder(BinaryTreeNode* ptr)
{
    if(ptr != nullptr)
    {
        thePostOrder(ptr->leftChild);
        thePostOrder(ptr->rightChild);
        callback(ptr);
    }
}

void LinkedBinaryTree::theLevelOrder(BinaryTreeNode* ptr)
{
    std::deque<BinaryTreeNode*> nodeList;
    nodeList.push_back(ptr);

    while(ptr != nullptr)
    {
        if(ptr->leftChild != nullptr)
            nodeList.push_back(ptr->leftChild);
        if(ptr->rightChild != nullptr)
            nodeList.push_back(ptr->rightChild);
        
        callback(ptr);
        nodeList.pop_front();
        ptr = nodeList.front();
    }
}

BinaryTreeNode* LinkedBinaryTree::theCopy(BinaryTreeNode* ptr)
{
    BinaryTreeNode* newNode;
    if(ptr == nullptr)
        return nullptr;
    else
    {
        newNode = new BinaryTreeNode(ptr->data);
        newNode->leftChild = theCopy(ptr->leftChild);
        newNode->rightChild = theCopy(ptr->rightChild);
        return newNode;
    }
}

int LinkedBinaryTree::theHeight(BinaryTreeNode* node)
{
    if(node == nullptr)
        return 0;
    
    int hl = theHeight(node->leftChild);
    int hr = theHeight(node->rightChild);
    
    if(hl > hr)
        return ++hl;
    else
        return ++hr;
}

int LinkedBinaryTree::height()
{
    return theHeight(boot);
}

void LinkedBinaryTree::init()
{   
    std::vector<BinaryTreeNode*> binaryVec;
    for(int i=0;i<7;++i)
        binaryVec.push_back(new BinaryTreeNode(i));
    
    binaryVec[0]->leftChild = binaryVec[1];
    binaryVec[0]->rightChild = binaryVec[2];

    binaryVec[1]->leftChild = binaryVec[3];
    binaryVec[1]->rightChild = binaryVec[4];
    binaryVec[2]->leftChild = binaryVec[5];
    binaryVec[2]->rightChild = binaryVec[6];

    boot = binaryVec[0]; 
}


