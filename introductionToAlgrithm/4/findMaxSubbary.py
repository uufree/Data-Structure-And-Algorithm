#!/usr/bin/env python3
# coding=utf-8

def findCorssSubbary(array,low,mid,hight):
    leftSum = -9999
    sm = 0
    for i in range(mid,low-1,-1):
        sm = sm + array[i]
        if sm > leftSum:
            leftSum = sm
            maxLeft = i

    rightSum = -9999
    sm = 0
    for i in range(mid+1,hight+1,1):
        sm = sm + array[i]
        if sm > rightSum:
            rightSum = sm
            maxRight = i

    return maxLeft,maxRight,leftSum+rightSum

def findMaxSubbary(array,low,hight):
    if hight == low:
        return low,hight,array[low]
    else:
        mid = (low + hight) // 2
        leftLow,leftHight,leftSum = findMaxSubbary(array,low,mid)
        rightLow,rightHight,rightSum = findMaxSubbary(array,mid+1,hight)
        crossLow,crossHight,crossSum = findCorssSubbary(array,low,mid,hight)

        if leftSum >= rightSum & leftSum >= crossSum:
            return leftLow,leftHight,leftSum
        elif rightSum >= leftSum & rightSum >= crossSum:
            return rightLow,rightHight,rightSum
        else:
            return crossLow,crossHight,crossSum


array_ = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]

low,hight,sm = findMaxSubbary(array_,0,15)

print("low: ",low)
print("hight: ",hight)
print("sum: ",sm)

