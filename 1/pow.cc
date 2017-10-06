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

int powFix2(int n,int m)
{
    int result = 1;
    int fix = n;

    while(m)
    {
        if(m & 1)
            result *= fix;
        m >>= 1;
        fix *= fix;
    }

    return result;
}

int main(int argc,char** argv)
{
    for(int i=0;i<1000000;++i)
        std::cout << powFix2(6,3) << std::endl;

    return 0;
}
