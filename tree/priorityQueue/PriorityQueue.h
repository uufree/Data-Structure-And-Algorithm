/*************************************************************************
	> File Name: priorityQueue.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月22日 星期六 11时09分30秒
 ************************************************************************/

#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

class PriorityQueue
{
    public:
        virtual bool empty() const = 0;
        virtual int size() const = 0;
        virtual const int& top() const = 0;
        virtual void pop() = 0;
        virtual void push(const int& num) = 0;
};


#endif
