/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 20时11分24秒
 ************************************************************************/

#include<iostream>
#include"ListNode.h"

int main(int argc,char** argv)
{
    ListNode<int> node(10);
    std::cout << node.show() << std::endl;;

    return 0;
}
