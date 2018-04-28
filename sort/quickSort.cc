/*************************************************************************
	> File Name: bubbleSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include"time.h"
#include<fstream>

int partition(long* array,int low,int high)
{
    int pos = rand() % (high-low+1);
    long temp = array[low+pos];
    array[low+pos] = array[low];
    array[low] = temp;
    
    while(low < high)
    {
        while(low < high)
            if(array[high] > temp)  
                high--;
            else
            {array[low++] = array[high];break;}
        
        while(low < high)
            if(array[low] < temp)
                low++;
            else
            {array[high--] = array[low];break;}
    }
    array[low] = temp;
    return low;
}

void qSort(long* array,int low,int high)
{
    if(high - low < 2)
        return;
    int mid = partition(array,low,high-1);
    qSort(array,low,mid);
    qSort(array,mid+1,high);
}

void quickSort(long* array,int length)
{
    qSort(array,0,length);
}

int main(int argc,char** argv)
{
    long total = 0;
    int arrayLength = 100000;
    long* array_r = NULL;

    for(int i=0;i<100;i++)
    {
        long* array = getArray();    //有100000个数字
        long begin = getTime();
        
        quickSort(array,arrayLength);
            
        long end = getTime();
        total += (end-begin);   
        array_r = array;
    }
    
    for(int i=0;i<arrayLength;i++)
        std::cout << array_r[i] << std::endl;
    
    std::cout << "Time: " << total/100 << std::endl;
    delete [] array_r;
    return 0;
}
