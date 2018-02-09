/*************************************************************************
	> File Name: add.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月09日 星期五 15时53分09秒
 ************************************************************************/

//二分递归数组求和
#include<iostream>

int sum(int* array,int low,int high)
{
    if(low == high)
        return array[low];
    else
        return sum(array,low,(low+high)>>1) + sum(array,((low+high)>>1)+1,high);
}


int main(int argc,char** argv)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    std::cout << sum(array,0,9) << std::endl;
    return 0;
}


