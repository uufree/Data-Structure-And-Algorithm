/*************************************************************************
	> File Name: maxPriorityQurue.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月22日 星期六 12时34分27秒
 ************************************************************************/

#ifndef _MAXPRIORITYQURUE_H
#define _MAXPRIORITYQURUE_H

#include"PriorityQueue.h"
#include<vector>

class MaxPriorityQueue : public PriorityQueue 
{
    public:
        MaxPriorityQueue(int size = 20);
        MaxPriorityQueue(const MaxPriorityQueue& lhs);
        MaxPriorityQueue(MaxPriorityQueue&& lhs);
        MaxPriorityQueue& operator=(const MaxPriorityQueue& lhs);
        MaxPriorityQueue& operator=(MaxPriorityQueue&& lhs);
        ~MaxPriorityQueue();

        bool empty() const override
        {return heapSize == 0;};

        int size() const override
        {return heapSize;};

        const int& top() const override;
        void pop() override;
        void push(const int& lhs) override;
        void init(int* heap_,int size);

    private:
        int* heap;
        int heapSize;
};
    




















#endif
