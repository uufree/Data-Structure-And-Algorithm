/*************************************************************************
	> File Name: 8.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月05日 星期六 05时54分27秒
 ************************************************************************/

#include<iostream>

struct ListNode
{
    int value;
    ListNode* next;
};

///////////////////////////////////////
//24
ListNode* treval(ListNode* node)
{
    if(node == NULL)
        return NULL;
    if(node->next == NULL)
        return node;

    ListNode* head_ = node;
    ListNode* head = node;
    ListNode* mid = head->next;
    ListNode* last = mid->next;
    
    while(mid)
    {
        last = mid->next;
        mid->next = head;
        head = mid;
        mid = last;
    }
    head_->next = NULL;
    return head;
}

////////////////////////////////////
//25

ListNode* merge(ListNode* head1,ListNode* head2)
{
    if(head1 == NULL && head2 != NULL)
        return head2;
    if(head2 == NULL && head1 != NULL)
        return head1;
    if(head1 == NULL && head2 == NULL)
        return NULL;
    
    
    ListNode* head = NULL;
    if(head1->value < head2->value)
    {
        head = head1;
        head1 = head1->next;
    }
    else
    {
        head = head2;
        head2 = head2->next;
    }
    ListNode* re = head;

    while(head1 && head2)
    {
        if(head1->value < head2->value)
        {
            head->next = head1;
            head1 = head1->next;
        }
        else
        {
            head->next = head2;
            head2 = head2->next;
        }
        
        head = head->next;
    }
    
    if(head1)
        head->next = head1;
    if(head2)
        head->next = head2;
    
    return re;
}

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

///////////////////////////////////
//26

bool hasSonTreeCore(BinaryTreeNode* nodeF,BinaryTreeNode* nodeS)
{
    if(nodeS == NULL)
        return true; 
    if(nodeF == NULL)
        return false;
    
    if(nodeF->value != nodeS->value)
        return false;
    return hasSonTreeCore(nodeF->left,nodeS->left) && hasSonTreeCore(nodeF->right,nodeS->right);
}

bool hasSonTree(BinaryTreeNode* nodeF,BinaryTreeNode* nodeS)
{
    bool result = false;
    if(nodeF && nodeS)
    {
        if(nodeF->value == nodeS->value)
            result = hasSonTreeCore(nodeF,nodeS);
        if(!result)
            result = hasSonTree(nodeF->left,nodeS);
        if(!result)
            result = hasSonTree(nodeF->right,nodeS);
    }
    return result;
}

int main(int argc,char** argv)
{
    ListNode* node = new ListNode;
    ListNode* head = node;
    node->value = 0;
    for(int i = 2;i<10;i+=2)
    {
        node->next = new ListNode;
        node = node->next;
        node->value = i;
    }
    node->next = new ListNode;
    node = node->next;
    node->value = 10;
    node->next = NULL;
     
    ListNode* node1 = new ListNode;
    ListNode* head1 = node1;
    node1->value = 1;
    for(int i = 3;i<10;i+=2)
    {
        node1->next = new ListNode;
        node1 = node1->next;
        node1->value = i;
    }
    node1->next = NULL;
    
    ListNode* pnode = merge(head,head1);
    while(pnode)
    {
        std::cout << pnode->value << std::endl;
        pnode = pnode->next;
    }

    return 0;
}
