/*************************************************************************
	> File Name: MaxPriorityQueueTest.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月23日 星期日 11时24分50秒
 ************************************************************************/

#include<iostream>
#include"MaxPriorityQueue.h"

int main(int argc,char** argv)
{
    MaxPriorityQueue queue;
    int* array = new int[11]{0,1,2,3,4,5,6,7,8,9,10};
    
    queue.init(array,20,11);
    queue.show();
    
    return 0;
}

