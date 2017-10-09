/*************************************************************************
	> File Name: gcdcn.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月09日 星期一 19时07分11秒
 ************************************************************************/

#include<iostream>

int gcdcn(int a,int b)
{
    int rank = 0;
    while(!((a & 1) || (b & 1)))
    {
        a >>= 1;
        b >>= 1;
        ++rank;
    }

    while(1)
    {
        while(!(a & 1))
            a >>= 1;
        while(!(b & 1))
            b >>= 1;

        a > b ? a = a-b : b = b-a;
        if(a == 0)
            return b << rank;
        if(b == 0)
            return a << rank;
    }

    return -1;
}



int main(int argc,char** argv)
{
    std::cout << gcdcn(2,5) << std::endl;
    return 0;
}


