/*************************************************************************
	> File Name: 15.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月12日 星期六 19时00分46秒
 ************************************************************************/

#include<iostream>

///////////////////////////////
//51-01
void getPairs(int* array,int length)
{
    if(array == NULL || length <= 0)
        return;

    int count = 0;;
    for(int i=0;i<length;i++)
    {
        for(int j=i+1;j<length;j++)
            if(array[i] > array[j])
                ++count;
    }

    std::cout << count << std::endl;
}

//////////////////////////////////////
//52
//获取两个链表的公共结点，先获取两个链表的长度，获取长度的差值，在长链表上先走n步，然后在一起走，直到遇到相同的结点

////////////////////////////////////
//53-01 
//数字在排序数组中出现的次数
int getFirst(int* array,int length,int start,int end,int key)
{
    if(start > end)
        return -1;

    int mid = (start + end) >> 1;
    int midData = array[mid];

    if(midData > key)
        end = mid;
    else if(midData < key)
        start = mid;
    else
    {
        if(array[mid-1] != key || mid == 0)
            return mid;
        else 
            end = mid;
    }

    return getFirst(array,length,start,end,key);
}

int getLast(int* array,int length,int start,int end,int key)
{
    if(start > end)
        return -1;

    int mid = (start + end) >> 1;
    int midData = array[mid];

    if(midData > key)
        end = mid;
    else if(midData < key)
        start = mid;
    else
    {
        if(array[mid+1] != key || mid == length-1)
            return mid;
        else
            start = mid;
    }
    
    return getLast(array,length,start,end,key);
}

void getNumber(int* array,int length,int key)
{
    if(array == NULL || length <= 0)
        return;

    for(int i=1;i<length;i++)
        if(array[i] < array[i-1])
            return;
    int first = getFirst(array,length,0,length+1,key);
    int last = getLast(array,length,0,length+1,key);
    std::cout << last - first + 1 << std::endl;
}

///////////////////////////////////////////
//53-02
//0~n-1中丢失的数字

int findNumber(int* array,int length)
{
    if(array == NULL || length <= 0)
        return -1;
    
    int start = 0;
    int end = length - 1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        int midData = array[mid];
        
        if(midData == mid)
            start = mid;
        else
        {
            if(mid == 0 || mid == length-1)
                return mid;
            if(array[mid-1]+1 != midData)
                return midData-1;
            if(array[mid+1]-1 != midData)
                return midData+1;

            if(midData < array[mid])
                end = mid;
            else
                start = mid;
        }
    }
    
    if(start == end)
        return end;
    return -1;
}

int main(int argc,char** argv)
{
    int array[8] = {1,2,3,4,6,7,8,9};
    std::cout << findNumber(array,8) << std::endl;
    return 0;
}

