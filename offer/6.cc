/*************************************************************************
	> File Name: 6.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月02日 星期三 07时27分35秒
 ************************************************************************/

#include<iostream>
#include<cstring>

double powerCore(double base,int expert)
{  
    double result = 1;
    for(int i=0;i<expert;i++)
        result *= base;
    return result;
}

double power(double base,int exper)
{
    if(exper == 0)
        return 1;

    double result = 0;
    if(exper > 0)
        result = powerCore(base,exper);
    else
    {
        result = powerCore(base,-exper);
        result = 1/result;
    }
    return result;
}


//循环+递归，理解起来有点麻烦啊．．
void printNumberCore(char* number,int length,int index)
{
    if(index == length - 1)
    {
        std::cout << number << std::endl;
        return;
    }
    
    for(int i=0;i<10;i++)
    {
        number[index+1] = i+'0';
        printNumberCore(number,length,index+1);
    }
}

void printNumber(int n)
{
    char* number = new char[n+1];
    number[n] = '\0';
    for(int i=0;i<10;i++)
    {
        number[0] = i + '0';
        printNumberCore(number,n,0);
    }

    delete [] number;
}

struct  ListNode
{
    int value;
    ListNode* next;
};

void deleteListNode(ListNode* head,ListNode* node)
{
    if(head == NULL || node == NULL)
        return;

    if(node->next != NULL)
    {
        std::swap(node->value,node->next->value);
        ListNode* deleteNode = node->next;
        node->next = deleteNode->next;

        delete deleteNode;
    }
    else if(head == node)
    {
        delete head;
        head = NULL;
    }
    else
    {
        ListNode* deleteNode = head;
        while(deleteNode != node)
            deleteNode = deleteNode->next;
        deleteNode->next = NULL;
        delete node;
    }
}

void duplicateList(ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return;
    
    ListNode* node = head;
    ListNode* nextNode = head->next;

    while(nextNode)
    {
        if(node->value == nextNode->value)
        {
            ListNode* deleteNode = nextNode;
            nextNode = nextNode->next;
            node->next = nextNode;
            delete deleteNode;
        }
        else
        {
            node = nextNode;
            nextNode = nextNode->next;
        }
    }
}

int main(int argc,char** argv)
{
    ListNode* head = new ListNode;
    ListNode* node = head;
    head->value = 0;

    for(int i=1;i<10;i++)
    {
        node->next = new ListNode;
        node->next->value = i;
        node = node->next;
    }
    node->next = NULL;
    node->next = new ListNode;
    node = node->next;
    node->value = 9;
    node->next = NULL;
   
    duplicateList(head);

    while(head != NULL)
    {
        std::cout << head->value << "    ";
        head = head->next;
    }
    std::cout << std::endl;

    return 0;
}
