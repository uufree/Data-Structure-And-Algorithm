/*************************************************************************
	> File Name: 6.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月02日 星期三 07时27分35秒
 ************************************************************************/

#include<iostream>

double powerCore(double base,int expert)
{  
    double result = 1;
    for(int i=0;i<expert;i++)
        result *= base;
    return result;
}

double power(double base,int exper)
{
    if(exper == 0)
        return 1;

    double result = 0;
    if(exper > 0)
        result = powerCore(base,exper);
    else
    {
        result = powerCore(base,-exper);
        result = 1/result;
    }
    return result;
}

int main(int argc,char** argv)
{
    std::cout << power(-10,-2) << std::endl;
    return 0;
}
