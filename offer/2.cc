/*************************************************************************
	> File Name: 2.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月01日 星期二 01时12分52秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>

long fibonacci(long n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}

long fibonacci_r(long n)
{
    if(n < 0)
        return -1;
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    
    long fib1 = 0;
    long fib2 = 1;
    long fibn = 0;

    for(int i=2;i<=n;i++)
    {
        fibn = fib1 + fib2;
        fib1 = fib2;
        fib2 = fibn;
    }

    return fibn;
}

//我去，输出最小元素就行了．．我还给人旋转了．．
int findMax(int* array,int length)
{
    int index = 0;
    int start = 0;
    int end = length - 1;
    while(1)
    {
        index = (start + end) >> 1;
        if(array[index-1]  < array[index] && array[index+1] > array[index] && array[index] > array[0])
            start = index;
        else if(array[index-1] < array[index] && array[index+1] < array[index])
            break;
        else if(array[index-1] < array[index] && array[index+1] > array[index] && array[index] < array[0])
            end = index;
        else if(array[index-1] > array[index] && array[index+1] > array[index])
        {
            index = index - 1;
            break;
        }
    }
    return index;
}

void trevl(int* array,int length)
{
    if(array == NULL || length <= 0)
        return;
    
    int maxIndex = findMax(array,length);
    int minIndex = maxIndex + 1;
    int minLength = length - minIndex;
    int midLength = length - minLength * 2;  
    

    for(int i=0;i<minLength;i++)    
        std::swap(array[i],array[length-1-i]);
    int times = midLength >> 1;
    for(int i=0;i<times;i++)
        std::swap(array[maxIndex-i],array[minLength+i]);
    
    times = minLength >> 1;
    for(int i=0;i<times;i++)
        std::swap(array[i],array[minLength-1-i]);
    times = (length - minLength) >> 1;
    for(int i=0;i<times;i++)
        std::swap(array[minLength+i],array[length-1-i]);
}

int main(int argc,char** argv)
{
    int array[10] = {4,5,6,7,8,9,0,1,2,3};
    trevl(array,10);
    for(int i=0;i<10;i++)
        std::cout << array[i] << "    ";
    std::cout << std::endl;

    return 0;
}

