/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月11日 星期一 16时34分45秒
 ************************************************************************/

#include"BinaryTreeNode.h"
#include<iostream>
#include<string>

int main(int argc,char** argv)
{
    BinaryTreeNode<std::string> node("uuchen");

    std::cout << node.element << std::endl;

    return 0;
}
