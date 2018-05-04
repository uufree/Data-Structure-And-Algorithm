/*************************************************************************
	> File Name: 7.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月04日 星期五 19时14分19秒
 ************************************************************************/

#include<iostream>

struct ListNode
{
    int value;
    ListNode* next;
};

//////////////////////////////////////
//21
void switchToArray(int* array,int length)
{
    int start = 0;
    int end = length - 1;

    while(start <= end)
    {
        while(array[start] % 2 == 0)
            ++start;
        while(array[end] % 2 != 0)
            --end;
        
        if(start < end)
            std::swap(array[start],array[end]);
    }
}

/////////////////////////////////////////
//22
void findRNode(ListNode* head,int index)
{
    if(head == NULL)
        return;
    int nodes = 0;
    ListNode* node = head;
    while(node)
    {
        node = node->next;
        ++nodes;
    }
    
    if(index > nodes-1)
        return;

    node = head;
    ListNode* curretNode = head;
    for(int i=0;i<index-1;i++)
        node = node->next;
    
    while(node->next)
    {
        node = node->next;
        curretNode = curretNode->next;
    }
    std::cout << curretNode->value << std::endl;
    return;
}

/////////////////////////////////////////////
//23
void findCircleStartNode(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return;
    ListNode* slow = head->next;
    if(slow->next == NULL)
        return;

    ListNode* fast = slow->next;
    while(slow != NULL && fast == NULL)
    {
        if(slow == fast)
            break;
        slow = slow->next;
        fast = fast->next;
        if(fast)
            fast = fast->next;
    }
    
    int loopSize = 1;
    while(fast->next != slow)
    {
        fast = fast->next;
        ++loopSize;
    }

    slow = fast = head;
    for(int i=0;i<loopSize;i++)
        slow = slow->next;
    while(fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
    }
}

int main(int argc,char** argv)
{
    ListNode* head = new ListNode;
    ListNode* node = head;

    for(int i=0;i<10;i++)
    {
        node->value = i;
        node->next = new ListNode;
        node = node->next;
    }
    node->value = 10;
    node->next = NULL;
    
    findRNode(head,10);

    return 0;
}
