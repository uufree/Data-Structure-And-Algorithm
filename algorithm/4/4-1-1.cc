/*************************************************************************
	> File Name: 4-1-1.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月05日 星期一 15时29分08秒
 ************************************************************************/

//使用递归的方式求解最大子数组问题

#include<iostream>

struct result
{
    int low = 0;
    int high = 0;
    int sum = 0;
};

struct result findMaxCrossingSubarray(int* array,int low,int mid,int high);
struct result findMaxSubarray(int* array,int low,int high);

int main(int argc,char** argv)
{
    int array[10] = {-1,-4,5,-7,3,10,-6,1,4,5};
    struct result res = findMaxSubarray(array,0,9);

    std::cout << "leftIndex: " << res.low << std::endl;
    std::cout << "rightIndex: " << res.high << std::endl;
    std::cout << "maxSubarray: " << res.sum << std::endl;

    return 0;
}

struct result  findMaxCrossingSubarray(int* array,int low,int mid,int high)
{
    int leftIndex = 0,rightIndex = 0,leftSum = -9999,rightSum = -9999,sum = 0;
    for(int i = mid;i >= low;i--)
    {
        sum += array[i];
        if(sum >= leftSum)
        {
            leftSum = sum;
            leftIndex = i;
        }
    }

    sum = 0;

    for(int i=mid+1;i<=high;i++)
    {
        sum += array[i];
        if(sum >= rightSum)
        {
            rightSum = sum;
            rightIndex = i;
        }
    }

    struct result res;
    res.low = leftIndex;
    res.high = rightIndex;
    res.sum = leftSum+rightSum;
    
    return res;
}

struct result findMaxSubarray(int* array,int low,int high)
{
    if(low == high)
    {
        struct result res;
        res.low = low;
        res.high = low;
        res.sum = array[low];
        return res;
    }
    else
    {
        int mid = (low + high) / 2;
        struct result leftRes = findMaxSubarray(array,low,mid);
        struct result rightRes = findMaxSubarray(array,mid+1,high);
        struct result crossRes = findMaxCrossingSubarray(array,low,mid,high);

        if(leftRes.sum >= rightRes.sum && leftRes.sum >= crossRes.sum)
            return leftRes;
        else if(rightRes.sum >= leftRes.sum && rightRes.sum >= crossRes.sum)
            return rightRes;
        else
            return crossRes;
    }
    
}

