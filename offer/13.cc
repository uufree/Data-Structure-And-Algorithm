/*************************************************************************
	> File Name: 13.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月11日 星期五 04时27分15秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>

//////////////////////////////////////////////
//41
struct max
{
    bool operator()(const int& a,const int& b){return a <= b;};
};

struct min
{
    bool operator()(const int& a,const int& b){return a >= b;};
};

void findMidNumber(int* array,int length)
{
    if(array == NULL || length <= 0)
        return;
    
    std::priority_queue<int,std::vector<int>,max> maxHeap;
    std::priority_queue<int,std::vector<int>,min> minHeap;
    
    //如何将流中的数据合理的分布在两个堆中？ 

    if(length % 2)
        std::cout << maxHeap.top() << std::endl;
    else
        std::cout << (maxHeap.top() + minHeap.top()) / 2 << std::endl;
}

///////////////////////////////////////////////////
//42
void findSubArrayMax(int* array,int length)
{
    if(array == NULL || length <= 0)
        return;

    int currentSum = 0;
    int lastGreatSum = 0;

    for(int i=0;i<length;i++)
    {
        if(currentSum <= 0)
            currentSum = array[i];
        else
            currentSum += array[i];

        if(currentSum >= lastGreatSum)
            lastGreatSum = currentSum;
    }

    std::cout << lastGreatSum << std::endl;
}

//////////////////////////////////////////////
//43
long accmulateOneCore(char* str)
{
    if(*str == '\0')
        return 0;

    long size = 0;
    int number = *str - '0';
    int order = strlen(str);
    
    if(number > 1)
        size = pow(10,order-1);
    else
        size = atoi(str+1);
    std::cout << size << std::endl;
    return size + accmulateOneCore(str+1);
}

void accmulateOne(char* str,int length)
{
    if(str == NULL || length <= 0)
        return ;

    long size = accmulateOneCore(str);
    std::cout << size << std::endl;
}

int main(int argc,char** argv)
{
    char number[6] = "34152";
    number[5] = '\0';
    
    char str[4] = "999";
    str[3] = '\0';

    accmulateOne(str,4);
    return 0;
}
