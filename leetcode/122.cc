/*************************************************************************
	> File Name: 122.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月26日 星期六 21时37分41秒
 ************************************************************************/

#include<iostream>
#include<vector>

int maxProfix(std::vector<int>& prices)
{
    if(prices.size() <= 1)
        return 0;

    int maxL = 0;
    int currentL = 0;
    int in = prices[0];
    int sum = 0;
    int size = prices.size();

    for(int i=0;i<size;)
    {
        if(i >= 1)
            in = prices[i];
        for(;i<size;i++)
        {
            currentL = prices[i] - in;
            std::cout << "in: " << in << "    ";
            std::cout << "prices[i] " << prices[i] << "    ";
            std::cout << "currentL: " << currentL << "    ";
            std::cout << "maxL: " << maxL << std::endl;
            if(currentL < 0)
            {
                if(maxL > 0)
                    sum += maxL;
                maxL = 0;
                currentL = 0;
                break;
            }
            else if(currentL < maxL)
            {
                sum += maxL;
                maxL = 0;
                currentL = 0;
                break;
            }
            else
                maxL = currentL;
        }
    }
    
    if(maxL > 0)
        sum += currentL;

    return sum;
}

int main(int argc,char** argv)
{
    std::vector<int> vec{7,6,4,3,1};
    std::cout << maxProfix(vec) << std::endl;;
    return 0;
}

