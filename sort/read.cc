/*************************************************************************
	> File Name: read.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月28日 星期六 18时30分51秒
 ************************************************************************/

#include<iostream>
#include<fstream>

int main(int argc,char** argv)
{
    std::fstream in("/home/uuchen/algorithm/sort/sortdata.dat",std::ios::in | std::ios::binary);
    if(!in.is_open())
        return -1;
    int index;
    while(in >> index)
        std::cout << index << std::endl;
    in.close();
    return 0;
}
