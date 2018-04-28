/*************************************************************************
	> File Name: heapSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include"time.h"
#include<fstream>

void adjustHeap(int* array,int index,int arrayLength)
{
    int temp = array[index];    //取出当前结点
    for(int i=2*index+1;i<arrayLength;i=2*i+1) //从当前结点的左子结点开始遍历
    {
        if(i+1 < arrayLength && array[i] < array[i+1])  //获取左右界结点中较小的
            i++;
        
        if(array[i] > temp)
        {
            array[index] = array[i];
            index = i;
        }
        array[index] = temp;
    }
}

void heapSort(int* array,int arrayLength)
{
    for(int i=arrayLength/2;i>=0;i--)
        adjustHeap(array,i,arrayLength);
    
    for(int i=arrayLength-1;i>=0;i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        adjustHeap(array,0,i);
    }    
}

int main(int argc,char** argv)
{
    long total = 0;
    int arrayLength = 100000;
    int temp;
    int* array_r = NULL;

    for(int i=0;i<10;i++)
    {
        int* array = getArray();    //有100000个数字
        long begin = getTime();
        
        heapSort(array,arrayLength);

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
