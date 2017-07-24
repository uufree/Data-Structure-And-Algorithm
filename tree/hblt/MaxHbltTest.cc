/*************************************************************************
	> File Name: MaxHbltTest.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月24日 星期一 11时23分46秒
 ************************************************************************/

#include<iostream>
#include"MaxHblt.h"
#include<deque>

int main(int argc,char** argv)
{
    std::deque<int> deq{1,2,3,4,5,6,7,8,9,10};
    MaxHblt maxHblt;
    maxHblt.init(deq); 
    maxHblt.show();

    return 0;
}

