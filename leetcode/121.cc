/*************************************************************************
	> File Name: maxProfit.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月26日 星期六 19时05分09秒
 ************************************************************************/

#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices)
{
    int maxL = 0;
    int current = 0;
    int in = prices[0];
    int size = prices.size();

    for(int i=1;i<size;i++)
    {
        if(prices[i] - in < 0)
            in = prices[i];
        else
        {
            current = prices[i] - in;
            if(current > maxL)
                maxL = current;
        }
    }

    return maxL;
}

int main()
{
    std::vector<int> vec = {7,1,5,3,6,4};
    std::cout << maxProfit(vec) << std::endl;
    return 0;
}
