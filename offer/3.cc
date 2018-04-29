/*************************************************************************
	> File Name: 3.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月29日 星期日 07时43分36秒
 ************************************************************************/

#include<iostream>

int duplication(int* array,int length)
{
    if(array == NULL || length < 2)
        return -1;
    
    for(int i=0;i<length;i++)
        if(array[i] < 0 || array[i] > length-1)
            return -1;

    int result = -1;
    for(int i=0;i<length;i++)
    {
        while(array[i] != i)
        {
            if(array[i] == array[array[i]])
            {
                result = array[i];
                break;
            }

            std::swap(array[i],array[array[i]]);
        }
    }
    return result;
}

int getNumber(int* array,int length,int start,int end)
{
    int count = 0;
    for(int i=0;i<length;i++)
        if(array[i] >= start || array[i] <= end)
            ++count;
    return count;
}

int duplication2(int* array,int length)
{
    if(array == NULL || length < 0)
        return -1;
    
    for(int i=0;i<length;i++)
        if(array[i] < 1 || array[i] > length-1)
            return -1;
    
    int start = 1;
    int end = length-1;
    while(start <= end)
    {
        int mid = (start + end) >> 1;
        int count = getNumber(array,length,start,end);
        
        if(end == start)
            return count > 1 ? end : -1;

        if(count > (mid-start+1))
            end = mid;
        else
            start = mid+1;
    }
    return -1;
}

int main(int argc,char** argv)
{
    int array[10] = {2,3,4,5,6,1,2,3,4,5};
    std::cout << duplication(array,10) << std::endl;

    return 0;
}

