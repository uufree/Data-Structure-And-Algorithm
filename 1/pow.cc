/*************************************************************************
	> File Name: pow.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月26日 星期二 22时32分53秒
 ************************************************************************/

#include<iostream>

int pow(int n,int m)
{
    if(m == 0)
        return 1;
    else
        return pow(n,m-1) * n;
}

int main(int argc,char** argv)
{
    std::cout << pow(10,2) << std::endl;

    return 0;
}
