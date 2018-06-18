/*************************************************************************
	> File Name: heapSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include<iostream>

void initHeap(int* array,int length)
{
    for(int i=length / 2;i>=1;i--)
    {
        int temp = array[i];
        int child = 2*i;
        while(child <= length)
        {
            if(child+1 <= length && array[child] < array[child+1])
                ++child;
            
            if(temp >= array[child])
                break;
            array[child/2] = array[child];
            child *= 2;
        }
        array[child/2] = temp;
    }
}

void pop(int* array,int length)
{
    std::swap(array[1],array[length]);
    int temp = array[1];
    int child = 1 * 2;
    while(child <= length)
    {
        if(child+1 < length && array[child] < array[child+1])
            ++child;

        if(temp >= array[child])
            break;
        array[child/2] = array[child];
        child *= 2;
    }
    array[child/2] = temp;
}

void print(int* array,int length)
{
    for(int i=1;i<length;i++)
        std::cout << pop(array) << "    ";
    std::cout << std::endl;
}

int main(int argc,char** argv)
{
    int* array = new int[11];
    for(int i=1;i<11;i++)
        array[i] = i;
    initHeap(array,10);
    print(array,10);
    
    for(int i=1;i<11;i++)
        push(array,i,i);
    print(array,10);

    delete [] array;
    return 0;
}
