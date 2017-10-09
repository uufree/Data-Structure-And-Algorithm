/*************************************************************************
	> File Name: resever.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月26日 星期二 22时27分34秒
 ************************************************************************/

#include<iostream>

void resever(int* array,int low,int hight)
{
    if(low < hight)
    {
        std::swap(array[low],array[hight]);
        resever(array,low+1,hight-1);
    }
}

int main(int argc,char** argv)
{
    int array[10] = {0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<10;++i)
        std::cout << array[i] << std::endl;

    resever(array,0,9);
    
    for(int i=0;i<10;++i)
        std::cout << array[i] << std::endl;

    return 0;
}



