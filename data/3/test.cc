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
    int array[10] = {1,2,3,4,5,6,7,7,7,7};
    List<int> list;
    for(int i=0;i<10;i++)
        list.insertAsLast(array[i]);
    
    list.uniquify();

    std::cout << "List Size: " << list.size() << std::endl;
    ListNode<int>* head = list.first()->_prev;
    while((head=head->_next) && (head != list.last()->_next))
        std::cout << head->_data << "   ";
    std::cout << std::endl;

    return 0;
}


