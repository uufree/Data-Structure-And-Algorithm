/*************************************************************************
	> File Name: bubbleSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include"time.h"
#include<fstream>

#define MAX_SIZE 78125
#define MAX_BLOCK 128

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

void readInBigData(std::fstream& in,long* array,int size)
{
    for(int i=0;i<size;i++)
        in >> array[i];
}

void writeInBigData(std::fstream& out,long* array,int size)
{
    for(int i=0;i<size;i++)
        out << array[i] << std::endl;
}

int main(int argc,char** argv)
{
    std::fstream in,out;
    in.open("/home/uuchen/algorithm/sort/BigDataSort.dat",std::ios::in | std::ios::binary);
    out.open("/home/uuchen/algorithm/sort/BigDataSort.dat",std::ios::out | std::ios::binary | std::ios::app);

    long* array = new long[78125];
    for(int i=0;i<128;i++)    
    {
        readInBigData(in,array,78125);
        writeInBigData(out,array,78125);
    }
    
    delete [] array;
    in.close();
    out.close();

    return 0;
}
