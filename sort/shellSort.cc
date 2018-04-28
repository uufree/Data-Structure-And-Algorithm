/*************************************************************************
	> File Name: shellSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 22时29分11秒
 ************************************************************************/

#include"time.h"
#include<fstream>

int main(int argc,char** argv)
{
    long total = 0;
    int arrayLength = 100000;
    int temp;
    int* array_r = NULL;

    for(int i=0;i<10;i++)
    {
        int* array = getArray();    
        long begin = getTime();
        
        for(int i=arrayLength/2;i>0;i/=2)
            for(int j=i;j<arrayLength;j++)
                for(int k=j;k-i>=0 && array[k]<array[k-i];k-=i)
                {
                    temp = array[k];
                    array[k] = array[k-i];
                    array[k-i] = temp;
                }

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

