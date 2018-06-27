/*************************************************************************
	> File Name: 237.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月23日 星期六 16时38分57秒
 ************************************************************************/

#include<iostream>
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int v) : val(v),next(nullptr){};
};

void deleteNode(ListNode* node)
{
    ListNode* next = node->next;

    while(1) {
        node->val = next->val;
        if(next->next == nullptr) 
            break;
        node = node->next;
        next = next->next;
    }
    node->next = nullptr;
}

int main(int argc,char** argv)
{
    ListNode* node = new ListNode(0);
    ListNode* head = node;

    for(int i=1;i<5;i++) {
        node->next = new ListNode(i);
        node = node->next;
    }
    
    ListNode* dnode = head->next;
    deleteNode(dnode);
    while(head) {
        std::cout << head->val << "    ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}
