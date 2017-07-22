/*************************************************************************
	> File Name: maxPriorityQurue.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月22日 星期六 12时34分48秒
 ************************************************************************/

#include"maxPriorityQurue.h"
#include<utility>

MaxPriorityQueue::MaxPriorityQueue(int size) :
    heapSize(size)
{
    heap = new int[size]; 
}

MaxPriorityQueue::MaxPriorityQueue(const MaxPriorityQueue& lhs) :
    heapSize(lhs.heapSize)
{
    heap = new int[heapSize];

    for(int i=0;i<heapSize;++i)
        heap[i] = lhs.heap[i];
}

MaxPriorityQueue::MaxPriorityQueue(MaxPriorityQueue&& lhs):
    heapSize(lhs.heapSize)
{
    heap = std::move(lhs.heap);
}

MaxPriorityQueue& MaxPriorityQueue::operator=(const MaxPriorityQueue& lhs)
{
    if(this->heap == lhs.heap)
        return *this;
    
    delete [] heap;
    heapSize = lhs.heapSize;
    heap = new int[heapSize];
    for(int i=0;i<heapSize;++i)
        heap[i] = lhs.heap[i];

    return *this;
}

MaxPriorityQueue& MaxPriorityQueue::operator=(MaxPriorityQueue&& lhs)
{
    delete [] heap;
    heapSize = lhs.heapSize;
    std::move(lhs.heap);

    return *this;
}

MaxPriorityQueue::~MaxPriorityQueue()
{
    delete [] heap;
}

const int& MaxPriorityQueue::top() const
{
    return heap[1];    
}

void MaxPriorityQueue::pop()
{
    if(heapSize == 0)
        return;

    int theElement = heap[heapSize];
    --heapSize;

    int currentNode = 1,child = 2;

    while(child <= heapSize)
    {
        if(child<heapSize && heap[child]<heap[child+1])
            ++child;

        if(theElement >= heap[child])
            break;

        heap[currentNode] = heap[child];
        currentNode = child;
        child *= 2;
    }
    heap[currentNode] = theElement;
}

void MaxPriorityQueue::push(const int& lhs)
{
    int currentNode = ++heapSize;
    while(currentNode!=1 && heap[currentNode/2] < lhs)
    {
        heap[currentNode] = heap[currentNode/2];
        currentNode/=2;
    }

    heap[currentNode] = lhs;
}

void MaxPriorityQueue::init(int* heap_,int size)
{
    delete [] heap;
    heap = heap_;
    heapSize = size;

    for(int root=heapSize/2;root>=1;--root)
    {
        int rootElement = heap[root];
        int child = root * 2;
        
        while(child != heapSize)
        {
            if(child<heapSize && heap[child]<heap[child+1])
                child++;
            if(rootElement >= heap[child])
                break;

            heap[child/2] = heap[child];
            child *= 2;
        }

        heap[child/2] = rootElement;
    }
}








