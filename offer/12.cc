/*************************************************************************
	> File Name: 12.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月11日 星期五 00时48分08秒
 ************************************************************************/

#include<iostream>

///////////////////////////////////////////
//38
void printAllStrCore(char* str,char* begin)
{
    if(*begin == '\0')
        std::cout << str << std::endl;
    else
    {
        for(char* ch = begin;*ch != '\0';ch++)
        {
            std::swap(*ch,*begin);
            printAllStrCore(str,begin+1);
            std::swap(*ch,*begin);
        }
    }
}

void printAllStr(char* str)
{
    if(str == NULL)
        return;
    printAllStrCore(str,str);
}

/////////////////////////////////////////////
//39
int findNumber(int* array,int length)
{
    if(array == NULL || length <= 0)
        return -1;
    int currentNumber = array[0];
    int currentSize = 1;

    for(int i=1;i<length;i++)
    {
        if(array[i] == currentNumber)
        {
            ++currentSize;
        }
        else
        {
            --currentSize;
            if(currentSize == 0)
            {
                currentNumber = array[i];
                currentSize = 1;
            }
        }
    }

    return currentNumber;
}

/////////////////////////////////////
//40 top(K)问题
void adjustHeap(int* array,int& length)
{
    int currentNode = 1;
    int child = 2;
    int temp = array[length--];

    while(child <= length)
    {
        if(child < length && array[child] > array[child+1])
            ++child;
        if(array[currentNode] >= temp)
            break;
        
        array[currentNode] = array[child];
        currentNode = child;
        child *= 2;;
    }
    array[currentNode] = temp;
}

void makeHeap(int* array,int length)
{
    for(int i = length/2;i>=1;i--)
    {
        int number = array[i];
        int child = 2*i;

        while(child <= length)
        {
            if(child < length && array[child] > array[child+1])
                child++;
            if(number <= array[child])
                break;
            array[child/2] = array[child];
            child *= 2;
        }
        array[child/2] = number;
    }
}

void printMins(int* array,int length,int number)
{
    if(array == NULL || length <= 0 || length < number)
        return;
    
    int* arrayC = new int[length+1];
    for(int i=0;i<length;i++)
        arrayC[i+1] = array[i];
    makeHeap(arrayC,length);
    

    for(int i=0;i<3;i++)
    {
        std::cout << arrayC[1] << std::endl;
        adjustHeap(arrayC,length);
    }
    
    delete [] arrayC;
}

int main(int argc,char** argv)
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    printMins(array,10,3);
    return 0;
}
