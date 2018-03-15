/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月15日 星期四 16时55分45秒
 ************************************************************************/

#include<iostream>
#include"vector.h"

int main(int argc,char** argv)
{
    int* array = new int[10];
    for(int i=0;i<10;i++)
        array[i] = i;
    
    Vector<int> vec(array,10);

    std::cout << "Array Size: " << vec.size() << std::endl;
    std::cout << "Array Capacity: " << vec.capacity() << std::endl;
    for(int i=0;i<vec.size();i++)
        std::cout << vec[i] << "    ";
    std::cout << std::endl;

    return 0;
}

