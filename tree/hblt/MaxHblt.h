/*************************************************************************
	> File Name: MaxHblt.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月24日 星期一 09时39分10秒
 ************************************************************************/

#ifndef _MAXHBLT_H
#define _MAXHBLT_H

#include<deque>

struct HbltNode final
{
    int node;
    int weight;
    HbltNode* leftChild;
    HbltNode* rightChild;

    HbltNode(int node_) : node(node_),weight(0),leftChild(nullptr),
        rightChild(nullptr)
    {};
    
    HbltNode(int node_,int weight_) : node(node_),weight(weight_),
        leftChild(nullptr),rightChild(nullptr)
    {};

    void setWeight(int weight_)
    {weight = weight_;};
};

class MaxHblt final
{
    public:
        MaxHblt();
        MaxHblt(const MaxHblt& lhs);
        MaxHblt(MaxHblt&& lhs);
        MaxHblt& operator=(const MaxHblt& lhs);
        MaxHblt& operator=(MaxHblt&& lhs);
        ~MaxHblt();

        void init(std::deque<int>& deq);
        void meld(const MaxHblt& node);
        void push(int node);
        int pop();
        void clear();
        void show();

    private:
        void theMeld(HbltNode* lhs,HbltNode* rhs);
        HbltNode* theCopy(HbltNode* lhs);
        void postOrder(HbltNode* node);

    private:
        HbltNode* root;
        int size;
};


























#endif
