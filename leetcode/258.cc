/*************************************************************************
	> File Name: 258.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月25日 星期五 19时40分23秒
 ************************************************************************/

#include<iostream>

int add(int num)
{
    if(num < 10)
        return num;

    int res = 0;
    while(num > 10)
    {
        res = num / 10;
        num /= 10;
        num += res;
    }
    return num;
}

int main(int argc,char** argv)
{
    std::cout << add(11) << std::endl;
    return 0;
}
