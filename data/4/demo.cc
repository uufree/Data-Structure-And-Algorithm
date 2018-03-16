/*************************************************************************
	> File Name: demo.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月15日 星期四 23时04分51秒
 ************************************************************************/

#include<iostream>
#include"stack.h"
#include<cstring>

void demo1();
void demo2(Stack<int>&,int,int);
void demo3();
void demo4();
void demo5();
void demo6();
void demo7();
void demo8();

int main(int argc,char** argv)
{
    Stack<int> stack;
    int int10 = 10;
    int int2 = 2;
    demo2(stack,int10,int2);
    
    std::cout << stack.size() << std::endl;

    while(!stack.empty())
        std::cout << stack.pop() << std::endl;
    
    return 0;
}

//逆序输出
void demo1()
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    Stack<int> stack;
    for(int i=0;i<10;i++)
        stack.push(array[i]);

    while(!stack.empty())
        std::cout << stack.pop() << std::endl;
}

//进制转换
//原理都是一样的,只是借助了栈来保存输出而已...
//demo2只演示递归版本10->2转换效果
void demo2(Stack<int>& stack,int int10,int int2)
{
    if(int10 > 0)
    {
        int n = int10 % int2;
        stack.push(n);
        demo2(stack,int10/int2,int2);
    }
}

//表达式求值
void demo3()
{
    static char[4][4] = 
    {
        {'','','',''},
        {'','','',''},
        {'','','',''},
        {'','','',''}
    };
    char const* math = "5+3*6-9/3";
    Stack<char> charStack;//运算符栈
    Stack<int> intStack;//运算数栈
    
    for(size_t i=0;i<strlen(math);i++)
    {
        
    }

}

























