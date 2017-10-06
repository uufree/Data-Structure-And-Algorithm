/*************************************************************************
	> File Name: max.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月06日 星期五 20时17分08秒
 ************************************************************************/

#include<iostream>

int maxI(int* array,int size)
{
    if(size == 1)
        return array[0];

    int temp = array[0];
    for(int i=1;i<size;++i)
    {
        if(temp < array[i])
            temp = array[i];
    }

    return temp;
}

int max(int a,int b)
{
    if(a < b)
        return b;
    return a;
}

int maxR(int* array,int low,int hight)
{
    if(low + 1 == hight)
        return array[low];
    else
    {
        int mid = (low + hight) >> 1;
        return max(maxR(array,low,mid),maxR(array,mid,hight));
    }
}

int main(int argc,char** argv)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,0};
    std::cout << maxI(array,10) << std::endl;
    std::cout << maxR(array,0,10) << std::endl;
    return 0;
}

