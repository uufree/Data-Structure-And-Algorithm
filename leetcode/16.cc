/*************************************************************************
	> File Name: 16.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月15日 星期二 14时39分14秒
 ************************************************************************/

//最接近的三数之和

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>

//我的答案超时了..

int main(int argc,char** argv)
{
    std::vector<int> nums = {0,0,0};
    int target = 1;
/*
    std::set<int> result;
    for(size_t i=0;i<nums.size()-2;i++)
        for(size_t j=i+1;j<nums.size()-1;j++)
            for(size_t k=j+1;k<nums.size();k++)
                result.insert(nums[i]+nums[j]+nums[k]);
   
    std::cout << "----------------" << std::endl;
    for(auto iter=result.begin();iter!=result.end();iter++)
        std::cout << *iter << "    ";
    std::cout << std::endl;
    std::cout << "----------------" << std::endl;
    
    std::set<int>::iterator iter=result.begin();
    if(result.size() > 1)
    {
        for(;iter!=result.end();++iter)
            if(*iter >= target)
                break;
    }
    
    std::cout << "*iter: " << *iter << std::endl;

    if(*iter == target)
        std::cout << *iter << std::endl;
    else
    {
        auto iter1 = iter;
        int left = (iter1 == result.begin()) ? *iter1 : *(--iter1);
        std::cout << "left: " << left << std::endl;
        int right = *iter;
        std::cout << "right: " << right << std::endl;
        if(abs(right-target) > abs(left-target))
            std::cout << left << std::endl;
        else
            std::cout << right << std::endl;
    }
*/
    if(nums.size() < 3)
        return 0;
    int cloesest = nums[0] + nums[1] + nums[2];
    if(cloesest == target)
        return target;
    std::sort(nums.begin(),nums.end());

    int second,third;
    int vsize = nums.size();
    for(size_t first=0;first<nums.size()-2;++first)
    {
        if(first > 0 && nums[first-1] == nums[first])
            continue;
        second = first+1;
        third = vsize-1;  
        while(second < third)
        {
            int currentSum = nums[first] + nums[second] + nums[third];
            if(currentSum == target)
                return target;
            if(abs(currentSum-target) < abs(cloesest-target))
                cloesest = currentSum;
            if(currentSum > target)
                --third;
            else
                ++second;
        }
    }

    return 0;
}
