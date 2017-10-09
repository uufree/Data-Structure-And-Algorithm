/*************************************************************************
	> File Name: resver.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月09日 星期一 19时21分37秒
 ************************************************************************/

#include<iostream>

void resver(int* array,int low,int hight)
{
    if((hight-low) & 1)
    {
        --hight;
        for(int i=0;i<(hight-low)>>1;++i)    
            std::swap(array[low+i],array[hight-i]);
    }
    else
    {
        int temp = (hight- low) >> 1;
        --hight;
        for(int i=0;i < temp;++i)
            std::swap(array[low+i],array[hight-i]);
    }
}

void shift(int* array,int arraySize,int shiftSize)
{
    resver(array,0,shiftSize);
    resver(array,shiftSize,arraySize);
    resver(array,0,arraySize);
}

int main(int argc,char** argv)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    shift(array,10,5);
    for(int i=0;i<10;++i)
        std::cout << array[i] << std::endl;

    return 0;
}
