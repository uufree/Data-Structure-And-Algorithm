/*************************************************************************
	> File Name: 168.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月24日 星期日 15时19分24秒
 ************************************************************************/

#include<iostream>
#include<string>

std::string convertToTitle(int n) {
    std::string res;
    while(n) {
        res = (char)((n-1)%26 + 'A') + res;
        n = (n-1)/26;
    }
    return res;
}

int main() 
{
    std::cout << convertToTitle(703) << std::endl;
    return 0;
}
