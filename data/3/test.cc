/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月08日 星期四 22时23分27秒
 ************************************************************************/

#include<iostream>
#include"list.h"

int main(int argc,char** argv)
{
    int array[10] = {2,8,9,1,4,3,7,5,0,6};
    List<int> list;
    for(int i=0;i<10;i++)
        list.insertAsFirst(array[i]);
    
    std::cout << "size: " << list.size() << std::endl;
    return 0;
}
