/*************************************************************************
	> File Name: hanoi.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月06日 星期五 20时52分37秒
 ************************************************************************/

#include<iostream>

//将ｘ借助ｙ移动到ｚ
void hanoi(int n,char x,char y,char z)
{
    if(n > 0)
    {
        hanoi(n-1,x,z,y);
        std::cout << "从　" << x << "　移动到　" << z << std::endl; 
        hanoi(n-1,y,x,z); 
    }
}

int main(int argc,char** argv)
{
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int size;
    std::cout << "请输入圆盘个数: ";
    std::cin >> size;

    hanoi(size,ch1,ch2,ch3);
    return 0;
}
