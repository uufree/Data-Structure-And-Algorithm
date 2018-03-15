/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月15日 星期四 22时53分41秒
 ************************************************************************/

#include<iostream>
#include"stack.h"

int main(int argc,char** argv)
{
    Stack<int> stack;
    int number = 5;
    stack.push(number);
    stack.push(number);
    stack.push(number);
    stack.push(number);
    
    int temp = stack.pop();
    std::cout << "Temp: " << temp << std::endl;

    std::cout << "Stack Size: " << stack.size() << std::endl;
    return 0;
}

