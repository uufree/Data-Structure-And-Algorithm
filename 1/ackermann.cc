/*************************************************************************
	> File Name: ackermann.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月09日 星期一 19时45分59秒
 ************************************************************************/

#include<iostream>

int mackermann(int m,int n)
{
    if(m > 0 && n > 0)
        return mackermann(m-1,mackermann(m,n-1));
    else if(m > 0 && n == 0)
        return mackermann(m-1,1);
    else if(m == 0)
        return n + 1;
    else
        return -1;
}

int main(int argc,char** argv)
{
    std::cout << mackermann(1,2) << std::endl;
    return 0;
}
