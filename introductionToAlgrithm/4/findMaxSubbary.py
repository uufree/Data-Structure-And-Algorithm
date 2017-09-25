#!/usr/bin/env python3
# coding=utf-8

def findCorssSubbary(array,low,mid,right):
    left-sm = -9999
    sm = 0
    for i in range(mid-1,low-1,-1):
        sm = sm + array[i]
        if sm > left-sm:
            left-sm = sm
            mx-left = i

    right-sm = -9999
    sm = 0
    for i in range(mid+1,hiht):
        sm = sm + array[i]
        if sm > right-sm:
            right-sm = sm
            mx-right = i

    return mx-left,mx-right,left-sm + right-sm

def findMaxSubbary(array,low,hight):
    if hight == low:
        return low,hight,array[low]
    else:
        mid = (low + hight) / 2
        left-low,left-hight,left-sm = findMaxSubbary(array,low,mid)
        right-low,right-hight,rihgt-sm = findMaxSubbary(array,mid+1,hight)
        cross-low,closs-hight,closs-sm = findCorssSubbary(array,low,mid,hight)

        if left-sm >= right-sm && left-sm >= cross-sm:
            return left-low,left-hight,left-sm
        elif right-sm >= left-sm && right-sm >= cross-sm:
            return right-low,right-hight,right-sm
        else:
            return cross-low,cross-hight,cross-sm


array_ = [13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7]

low,hiht,sm = findMaxSubbary(array_,0,15)

print("low: ",low)
print("hight: ",hight)
print("sum: ",sm)











