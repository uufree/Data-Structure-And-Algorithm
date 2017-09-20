/*************************************************************************
	> File Name: 1002.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月20日 星期三 16时27分43秒
 ************************************************************************/

#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<string>
#include<stdlib.h>
#include<stdio.h>

int main(int argc,char** argv)
{
    std::string number;
    std::cin >> number;
    std::vector<int> vec;
    std::map<int,std::string> Map{{0,"ling"},{1,"yi"},{2,"er"},{3,"san"},{4,"si"},{5,"wu"},{6,"liu"},{7,"qi"},{8,"ba"},{9,"jiu"}};

    int size = number.size();
    if(size > 100)
        return 0;

    int res = 0;
    for(int i=0;i<size;++i)
        res += static_cast<int>(number[i] - 48);  
    
    int a,b;
    if(res >= 100)
    {
        for(int i=2;i>=0;--i)
        {
            b = pow(10,i);
            a = res / b;
            res = res % b;
            
            if(i != 0)
                std::cout << Map[a] << " ";
            else
                std::cout << Map[a];
        }
    }
    else if(res < 100 && res >= 10)
    {
        for(int i=1;i>=0;--i)
        {
            b = pow(10,i);
            a = res / b;
            res = res % b;
            
            if(i != 0)
                std::cout << Map[a] << " ";
            else
                std::cout << Map[a];
        }
    }
    else
        std::cout << Map[res];

    return 0;
}
