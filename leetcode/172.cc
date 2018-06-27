/*************************************************************************
	> File Name: 172.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月24日 星期日 15时36分31秒
 ************************************************************************/

#include<iostream>

int target(int n) {
    return n < 25 ? n/5 : n/5+target(n/5);
}

int main()
{
    std::cout << target(7) << std::endl;
    return 0;
}
