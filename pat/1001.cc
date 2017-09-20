/*************************************************************************
	> File Name: 1001.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月20日 星期三 16时09分47秒
 ************************************************************************/

#include<iostream>

int main(int argc,char** argv)
{
    int number;
    std::cin >> number;

    if(number > 1000 || number <= 0)
        return 0;
    
    int size = 0;
    while(1)
    {
        if(number%2 == 0)
        {
            number /= 2;
            ++size;
        }
        else
        {
            number = 3*number + 1;
            number /= 2;
            ++size;
        }

        if(number != 1)
            continue;
        else
        {
            std::cout << size << std::endl;
            break;
        }
    }
    
    return 0;
}

