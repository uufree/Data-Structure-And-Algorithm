/*************************************************************************
	> File Name: write.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 23时07分55秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<limits>

int main(int argc,char** argv)
{
    std::fstream out;
    out.open("/home/uuchen/algorithm/sort/BigDataSort.dat",std::ios::out | std::ios::binary | std::ios::app);

    for(int i=0;i<10000000;i++)
        out << rand() % std::numeric_limits<long>::max() << std::endl;
     
    return 0;
}

