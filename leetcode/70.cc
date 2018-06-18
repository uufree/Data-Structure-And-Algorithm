/*************************************************************************
	> File Name: 70.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月28日 星期一 21时12分14秒
 ************************************************************************/

#include<iostream>

int climCoreCore(int n)
{
    int c = 1;
    int a = 1;
    int b = 1;

    for(;n > 1;n--)
    {
        a = b;
        b = c;
        c = a + b;
    }
    
    return c;
}

int main()
{
    std::cout << climCoreCore(2) << std::endl;
    return 0;
}
