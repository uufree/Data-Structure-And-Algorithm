/*************************************************************************
	> File Name: 4.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月30日 星期一 07时32分50秒
 ************************************************************************/

#include<iostream>
#include<cstring>

bool find(int* array,int rows,int columns,int key)
{
    if(array == NULL || rows < 0 || columns < 0)
        return false;

    int rowPos = 0;
    int columnPos = 0;

    while(rowPos < rows && columnPos < columns)
    {
        if(rowPos == rows-1 && columnPos == columns-1 && array[columns * rowPos + columnPos] < key)
            return false;

        int value = array[columns * rowPos + columnPos];
        if(key < value)
        {
            for(int i=columnPos;i>=0;i--)
                if(array[columns * rowPos + i] == key)
                    return true;
            for(int i=rowPos;i>=0;i--)
                if(array[columns * i + columnPos] == key)
                    return true;
            return false;
        }
        else if(key == value)
            return true;
        
        if(++rowPos == rows)
            rowPos = rows - 1;
        if(++columnPos == columns)
            columnPos = columns - 1;
    }
    return false;
}

char* replace(const char* str,int length)
{
    int kCount = 0;
    for(int i=0;i<length;i++)
        if(str[i] == ' ')
            ++kCount;

    int newLength = length + kCount * 2;
    char* newStr = new char[newLength];
    memset(newStr,'\0',newLength);
    strncpy(newStr,str,length);

    char* tail = newStr+newLength-1;
    char* current = newStr + length-1;

    while(current != newStr)
    {
        if(*current != ' ')
        {
             *tail = *current;
             --tail;
             --current;
        }
        else
        {
            *tail = '0';
            --tail;
            *tail = '2';
            --tail;
            *tail = '%';
            --tail;
            --current;
        }
    }
    
    return newStr;
}

struct ListNode
{
    int value;
    ListNode* next;
};

void printList(ListNode* node)
{
    if(node->next != NULL)
        printList(node->next);
    std::cout << node->value << std::endl;
}

int main(int argc,char** argv)
{
    ListNode* head = new ListNode;
    ListNode* current = head;
    head->value = 0;
    for(int i=1;i<10;i++)
    {
        current->next = new ListNode;
        current = current->next;
        current->value = i;
        current->next = NULL;
    }
    
    printList(head);

    return 0;
}


