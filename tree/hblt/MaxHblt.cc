/*************************************************************************
	> File Name: MaxHblt.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月24日 星期一 09时39分21秒
 ************************************************************************/

#include<iostream>
#include"MaxHblt.h"

MaxHblt::MaxHblt()
{};

MaxHblt::MaxHblt(const MaxHblt& lhs) :
    size(lhs.size)
{
    root = theCopy(lhs.root);
}

MaxHblt::MaxHblt(MaxHblt&& lhs) :
    root(std::move(lhs.root)),
    size(lhs.size)
{};

MaxHblt& MaxHblt::operator=(const MaxHblt& lhs)
{
    if(size !=0 )
    {
        for(int i=0;i<size;++i)
            pop();
    }
    size = lhs.size; 
    root = theCopy(lhs.root);

    return *this;
}

MaxHblt& MaxHblt::operator=(MaxHblt&& lhs)
{
    if(size != 0)
    {
        for(int i=0;i<size;++i)
            pop();
    }
    size = lhs.size;
    root = std::move(lhs.root);
    
    return *this;
}

MaxHblt::~MaxHblt()
{
    if(size != 0)
    {
        for(int i=0;i<size;++i)
            pop();
    }
}

HbltNode* MaxHblt::theCopy(HbltNode* lhs)
{
    if(lhs == nullptr)
        return nullptr;
    else
    {
        HbltNode* newNode = new HbltNode(lhs->node,lhs->weight);
        newNode->leftChild = theCopy(lhs->leftChild);
        newNode->rightChild = theCopy(lhs->rightChild);
        return newNode;
    }
}

void MaxHblt::meld(const MaxHblt& node)
{
    theMeld(root,node.root);
    size += node.size;
}

void MaxHblt::theMeld(HbltNode* lhs,HbltNode* rhs)
{
    if(rhs == nullptr)
        return;

    if(lhs == nullptr)
    {
        lhs = rhs;
        return;
    }

    if(lhs->node < rhs->node)
        std::swap(lhs,rhs);

    theMeld(lhs->rightChild,rhs);
    
    if(lhs->leftChild == nullptr)
    {
        lhs->leftChild = lhs->rightChild;
        lhs->rightChild = nullptr;
        lhs->weight = 1;
    }
    else
    {
        if(lhs->leftChild->weight < lhs->rightChild->weight)
            std::swap(lhs->leftChild,lhs->rightChild);
        
        lhs->weight = lhs->rightChild->weight + 1;
    }
}

void MaxHblt::push(int node_)
{
    HbltNode* node = new HbltNode(node_);
    theMeld(root,node);
    ++size;
}

int MaxHblt::pop()
{
    if(size == 0)
        return 0;

    HbltNode* left = root->leftChild;
    HbltNode* right = root->rightChild;
    theMeld(left,right);
    --size;
    int element = root->node;
    delete root;
    root = left;

    return element;
}

void MaxHblt::init(std::deque<int>& deq)
{
    std::deque<HbltNode*> nodeDeque;

    for(auto iter : deq)
    {
        HbltNode* newNode = new HbltNode(iter);
        nodeDeque.push_back(newNode);
    }

    HbltNode* left = nullptr;
    HbltNode* right = nullptr;
    
    size = nodeDeque.size();
    
    for(int i=0;i<size-1;++i)
    {
        left = nodeDeque.front();
        nodeDeque.pop_front();
        right = nodeDeque.front();
        nodeDeque.pop_front();
        theMeld(left,right);
        nodeDeque.push_back(left);
    }
    
    root = nodeDeque.front(); 
}

void MaxHblt::show()
{
    postOrder(root); 
}

void MaxHblt::postOrder(HbltNode* node)
{
    if(node != nullptr)
    {
        std::cout << "node->weight: " << node->weight << std::endl;
        std::cout << "node->node: " << node->node << std::endl;
        postOrder(node->leftChild);
        postOrder(node->rightChild);
    }
}
