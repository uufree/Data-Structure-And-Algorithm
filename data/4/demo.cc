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
    demo3();

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

int calcuate(int,char,int);
int calcuate(int num1,char op,int num2)
{
    if(op == '+')
        return num1 + num2;
    else if(op == '-')
        return num1 - num2;
    else if(op == '*')
        return num1 * num2;
    else if(op == '/')
        return num1 / num2;
    else
        return -1;
}
//表达式求值

int getPosInOperator(char ch);
int getPosInOperator(char ch)
{
    if(ch == '+')
        return 0;
    else if(ch == '-')
        return 1;
    else if(ch == '*')
        return 2;
    else if(ch == '/')
        return 3;
    else
        return -1;
}

void demo3()
{
//[栈顶] [当前] OK?
//+ - * / \0
    static char op[5][5] = 
    {
        {'>','>','<','<','>'},
        {'>','>','<','<','>'},
        {'>','>','>','>','>'},
        {'>','>','>','>','>'},
        {'<','<','<','<','='}
    };

    char const* math = "5+3*6-9/3";
    Stack<char> charStack;//运算符栈
    Stack<int> intStack;//运算数栈
    
    charStack.push(op[4][4]);
    
    while(!charStack.empty())//以栈是否为空来进行计算呐
    {
        char ch = *math;//获得当前的字符串
        int number = -1;
        if(ch > 47 || ch < 58)//计算数入栈
        {
           number = ch - 48; 
           intStack.push(number);
        }
        else//非计算数进行判断,然后再处理
        {
            int stackTopPos = getPosInOperator(charStack.top());
            int currentPos = getPosInOperator(ch);
            char oper = op[stackTopPos][currentPos];

            switch(oper)
            {
                case '<':
                    charStack.push(ch);math++;
                    break;
                case '=':
                    charStack.pop();math++;
                    break;
                case '>':
                {
                    int num2 = intStack.pop();
                    int num1 = intStack.pop();
                    int result = calcuate(num1,ch,num2);
                    intStack.push(result);
                }
            }
        }
    }

    std::cout << "Result: " << intStack.pop() << std::endl;
}

























