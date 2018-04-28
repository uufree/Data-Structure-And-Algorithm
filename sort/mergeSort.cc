/*************************************************************************
	> File Name: bubbleSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include"time.h"
#include<fstream>
#include<limits>

void merge(long* array,int low,int mid,int high)
{
    int lowLen = mid - low + 1;
    int highLen = high - mid;
    long* lowArray = new long[lowLen+1];
    long* highArray = new long[highLen+1];
    
    for(int i=0;i<lowLen;i++)
        lowArray[i] = array[low+i];
    lowArray[lowLen] = std::numeric_limits<int>::max();
    
    for(int i=0;i<highLen;i++)
        highArray[i] = array[mid+1+i];
    highArray[highLen] = std::numeric_limits<int>::max();
    
    int lowIndex = 0;
    int highIndex = 0;
    for(;low <= high;low++)
    {
        if(lowArray[lowIndex] < highArray[highIndex])
        {
            array[low] = lowArray[lowIndex];
            ++lowIndex;
        }  
        else
        {
            array[low] = highArray[highIndex];
            ++highIndex;
        }
    }

    delete [] lowArray;
    delete [] highArray;
}

void mSort(long* array,int low,int high)
{
    if(low < high)
    {
        int mid = (low + high) >> 1;
        mSort(array,low,mid);
        mSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

void mergeSort(long* array,int length)
{
    mSort(array,0,length-1); 
}

int main(int argc,char** argv)
{
    long total = 0;
    int arrayLength = 100000;
    long* array_r = NULL;

    for(int i=0;i<10;i++)
    {
        long* array = getArray();    //有100000个数字
        long begin = getTime();
        
        mergeSort(array,arrayLength);

        long end = getTime();
        total += (end-begin);   
        array_r = array;
    }
    
    for(int i=0;i<arrayLength;i++)
        std::cout << array_r[i] << std::endl;
    
    std::cout << "Time: " << total/10 << std::endl;
    delete [] array_r;
    return 0;
}
