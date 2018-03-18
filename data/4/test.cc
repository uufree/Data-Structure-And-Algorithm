/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月15日 星期四 22时53分41秒
 ************************************************************************/

#include<iostream>
#include"stack.h"
#include"deque.h"

struct queen
{
    int number;
    int high;
};

int main(int argc,char** argv)
{
    Deque<int> deque;
    
    for(int i=0;i<10;i++)
        deque.push(i);
    
    std::cout << "Deque Size: " << deque.size() << std::endl;
    std::cout << "Deque Top: " << deque.top() << std::endl;
    std::cout << "Deque Tail: " << deque.tail() << std::endl;

    return 0;
}

