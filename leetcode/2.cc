
#include<iostream>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int val_) : val(val_),next(NULL) {};
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* result = head;
        int l1Length = 0;
        int l2Length = 0;
        
        ListNode* ls1 = l1;
        ListNode* ls2 = l2;
        while(ls1 != NULL)
        {
            ++l1Length;
            ls1 = ls1->next;
        }
        
        while(ls2 != NULL)
        {
            ++l2Length;
            ls2 = ls2->next;
        }
        
        int length = std::max(l1Length,l2Length);
        int temp = 0;
        for(int i=0;i<length;i++)
        {
            if(l1 != NULL && l2 != NULL)
            {
                head->val = l1->val + l2->val + temp;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 != NULL && l2 == NULL)
            {
                head->val = l1->val + temp;
                l1 = l1->next;
            }
            else if(l1 == NULL && l2 != NULL)
            {
                head->val = l2->val + temp;
                l2 = l2->next;
            }
            
            if(head->val >= 10)
            {
                temp = head->val / 10;
                head->val = head->val % 10;
            }
            else
            {
                temp = 0;
            }
            
            if(i != length-1)
            {
                head->next = new ListNode(0);
                head = head->next;
            }
                
            if(i == length-1 && temp != 0)
                head->next = new ListNode(temp);
        }
        
        return result;
        
    }

int main(int argc,char** argv)
{
    ListNode* l1 = new ListNode(5);
    ListNode* l1s = l1;
    
    ListNode* l2 = new ListNode(5);
    ListNode* l2s = l2;

    ListNode* res = addTwoNumbers(l1s,l2s);
    
    while(res != NULL)
    {
        std::cout << res->val << std::endl;
        res = res->next;
    }

    return 0;
}
