/*************************************************************************
	> File Name: 594.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月26日 星期二 22时27分37秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unistd.h>
using namespace std;
int findLHS(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        sort(nums.begin(),nums.end());
        queue<int> queue;
        int last = nums[0];
        for(int i=1;i<nums.size();i++) {
            if(last != nums[i]) {
                queue.push(i);
                last = nums[i];
            }
        }
        int max = 1,current = 1;
        int aim = nums[0];
        for(int i=1;i<length;i++) {
            if(aim==nums[i] || aim==nums[i]-1) {
                ++current;
                if(current>max && aim==nums[i]-1)
                    max = current;
            } else {
                i = queue.front();
                queue.pop();
                aim = nums[i];
                current = 1;
            }
        }
        return max;
    }

int main()
{
    vector<int> vec{1,4,1,3,1,-14,1,-13};
    std::cout << findLHS(vec) << std::endl;
}

