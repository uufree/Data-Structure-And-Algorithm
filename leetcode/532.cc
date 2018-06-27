/*************************************************************************
	> File Name: 532.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月25日 星期一 21时33分52秒
 ************************************************************************/
#include<vector>
using namespace std;
#include<iostream>
#include<algorithm>

int findPairs(vector<int>& nums, int k) {
        if(nums.size() == 0)
            return 0;
        int length = nums.size(),res = 0;
        sort(nums.begin(),nums.end());
        if(k == 0) {
            int last = nums[0],current;
            for(int i=1;i<length;i++) {
                current = nums[i];
                if(last != current) {
                    last = current;
                } else {
                    ++res;
                }
            }
            return res;
        }
        
        auto iter = unique(nums.begin(),nums.end());
        nums.erase(iter,nums.end());
        length = nums.size();
        for(int i=0;i<length-1;i++) {
            for(int j=i+1;j<length;j++) {
                if(nums[j] - nums[i] < k)
                    continue;
                else if(nums[j] -nums[i] == k)
                    ++res;
                else if(nums[j] - nums[i] > k)
                    break;
            }
        }
        return res;
    }

int main()
{
    vector<int> vec{-1,-1,1,1};
    std::cout << findPairs(vec,0) << std::endl;
    return 0;
}
