/*************************************************************************
	> File Name: selectSort.cc
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
    
        for(int i=0;i<arrayLength;i++)
            for(int j=i+1;j<arrayLength;j++)
                if(array[i] > array[j])
                {
                    temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
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
