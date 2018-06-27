/*************************************************************************
	> File Name: 141.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月26日 星期二 21时55分01秒
 ************************************************************************/

#include<iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v),next(nullptr){};
};
 bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;
        ListNode* fast = head->next;
        ListNode* slow = head;
        bool hasCircle = false;
        while(fast!=nullptr) {
            fast = fast->next;
            if(slow == fast) {
                hasCircle = true;
                break;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return hasCircle;
    }

int main(int argc,char** argv) 
{
    ListNode node(10);
    node.next = &node;
    std::cout << hasCycle(&node) << std::endl;
    return 0;
}
