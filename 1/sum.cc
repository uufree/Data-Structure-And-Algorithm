/*************************************************************************
	> File Name: sum.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月26日 星期二 22时12分48秒
 ************************************************************************/

#include<iostream>

int sum(int* array,int n)
{
    if(n < 1)
        return 0;
    else
        return sum(array,n-1) + array[n-1];
}

int main(int argc,char** argv)
{
    int array[10] = {1,2,3,4,5,6,7,8,9,10};
        
    int sm = sum(array,10);

    std::cout << sm << std::endl;
    return 0;
}
