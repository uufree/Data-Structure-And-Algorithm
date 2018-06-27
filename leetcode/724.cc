/*************************************************************************
	> File Name: 724.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月24日 星期日 20时59分21秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
        int left = 0,right = nums.size()-1,leftSum = nums[0],rightSum = nums[nums.size()-1];
        int res = -1;
        while(left < right ) {
            std::cout << "left: " << left << std::endl;
            std::cout << "right: " << right << std::endl;
            if(leftSum < rightSum) {
                ++left;
                leftSum += nums[left];
            } else if(leftSum > rightSum) {
                --right;
                rightSum += nums[right];
            } else if(leftSum == rightSum) {
                if(left+1 == right-1) {
                    res = left + 1;
                }
                break;
            }
        }
        return res;
    }

int main(int argc,char** argv)
{
    vector<int> vec{-1,-1,-1,-1,-1,0};
    std::cout << pivotIndex(vec) << std::endl;
    return 0;
}
