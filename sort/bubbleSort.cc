/*************************************************************************
	> File Name: bubbleSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 17时28分02秒
 ************************************************************************/

#include"time.h"
#include<fstream>

int main(int argc,char** argv)
{
    long total = 0;
    int arrayLength = 100000;
    int temp;
    int* array_r = NULL;

    for(int i=0;i<1;i++)
    {
        int* array = getArray();    //有100000个数字
        long begin = getTime();
    
        for(int i=0;i<arrayLength-1;i++)
            for(int j=0;j<arrayLength-1-i;j++)
                if(array[j] > array[j+1])
                {
                    temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }

        long end = getTime();
        total += (end-begin);   
        array_r = array;
    }
    
    for(int i=0;i<arrayLength;i++)
        std::cout << array_r[i] << std::endl;
    
    std::cout << "Time: " << total/1 << std::endl;
    delete [] array_r;
    return 0;
}
