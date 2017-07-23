/*************************************************************************
	> File Name: maxPriorityQurue.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月22日 星期六 12时34分48秒
 ************************************************************************/

#include"MaxPriorityQueue.h"
#include<utility>
#include<iostream>

MaxPriorityQueue::MaxPriorityQueue(int size) :
    heapSize(size)
{
    heap = new int[size]; 
}

MaxPriorityQueue::MaxPriorityQueue(const MaxPriorityQueue& lhs) :
    heapSize(lhs.heapSize),
    dataSize(lhs.dataSize)
{
    heap = new int[heapSize];

    for(int i=0;i<dataSize;++i)
        heap[i] = lhs.heap[i];
}

MaxPriorityQueue::MaxPriorityQueue(MaxPriorityQueue&& lhs):
    heapSize(lhs.heapSize),
    dataSize(lhs.dataSize)
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
    dataSize = lhs.dataSize;

    for(int i=0;i<dataSize;++i)
        heap[i] = lhs.heap[i];

    return *this;
}

MaxPriorityQueue& MaxPriorityQueue::operator=(MaxPriorityQueue&& lhs)
{
    delete [] heap;
    heapSize = lhs.heapSize;
    dataSize = lhs.dataSize;
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
    if(dataSize == 0)
        return;

    int theElement = heap[dataSize];
    --dataSize;

    int currentNode = 1,child = 2;

    while(child <= dataSize)
    {
        if(child<dataSize && heap[child]<heap[child+1])
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
    int currentNode = ++dataSize;
    while(currentNode!=1 && heap[currentNode/2] < lhs)
    {
        heap[currentNode] = heap[currentNode/2];
        currentNode/=2;
    }

    heap[currentNode] = lhs;
}

void MaxPriorityQueue::init(int* heap_,int heapSize_,int dataSize_)
{
    delete [] heap;
    heap = heap_;
    heapSize = heapSize_;
    dataSize = dataSize_;
    
    show();

    for(int root=dataSize/2;root>=1;--root)
    {
        int rootElement = heap[root];
        int child = root * 2;
        
        while(child <= dataSize)
        {
            if(child<dataSize && heap[child]<heap[child+1])
                child++;
            if(rootElement >= heap[child])
                break;

            heap[child/2] = heap[child];
            child *= 2;
        }

        heap[child/2] = rootElement;
    }
}

void MaxPriorityQueue::show() const
{
    std::cout << "heapSize: " << heapSize << std::endl;
    std::cout << "dataSize: " << dataSize << std::endl;
    for(int i=1;i<dataSize;++i)
        std::cout << heap[i] << std::endl;
}






