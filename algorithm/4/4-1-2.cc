/*************************************************************************
	> File Name: 4-1-2.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月05日 星期一 16时13分16秒
 ************************************************************************/

//使用暴力算法求解最大子数组问题

#include<iostream>
#include<vector>

struct result
{
    int low = 0;
    int high = 0;
    int sum = 0;

    result(int low_,int high_,int sum_) : low(low_),high(high_),sum(sum_){};
};

int main(int argc,char** argv)
{
    int array[10] = {-1,4,-5,7,-3,10,-6,1,-4,5};
    std::vector<struct result> resultArray;
    for(int i = 0;i <= 9;i++)
    {
        for(int j = i;j <= 9;j++)
        {
            int num = 0;
            for(int k = i;k <= j;k++)
                num += array[k];
            struct result res(i,j,num);
            resultArray.push_back(res); 
        }
    }
    
    int index = 0;
    int jeffer = -9999;
    for(int i=0;i<55;i++)
    {
        if(resultArray[i].sum > jeffer)
        {
            jeffer = resultArray[i].sum;
            index = i;
        }
    }

    std::cout << "leftIndex: " << resultArray[index].low << std::endl;
    std::cout << "rightIndex: " << resultArray[index].high << std::endl;
    std::cout << "maxSubarray: " << resultArray[index].sum << std::endl;
    
    return 0;
}

