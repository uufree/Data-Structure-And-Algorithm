/*************************************************************************
	> File Name: test.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月29日 星期日 05时24分01秒
 ************************************************************************/

#include<iostream>
#include"time.h"
#include<cstdlib>

int partition(long* array,int low,int high)
{
    int pos = 2;
    std::cout << "pos: " << pos << std::endl;
    long temp = array[low+pos];
    array[low+pos] = array[low];
    array[low] = temp;
    
    while(low < high)
    {
        while(low < high)
            if(array[high] > temp)  
                high--;
            else
            {array[low++] = array[high];break;}
        
        while(low < high)
            if(array[low] < temp)
                low++;
            else
            {array[high--] = array[low];break;}
    }
    array[low] = temp;
    return low;
}

int part(long* array,int low,int high)
{
    int pos = 2;
    std::cout << "pos: " << pos << std::endl;
    std::swap(array[low],array[pos]);
    long temp = array[low];

    while(low < high)
    {
        while(low < high)
            if(array[high] > temp)
                --high;
            else
            {array[low++] = array[high];break;}
        
        while(low < high)
            if(array[low] < temp)
                ++low;
            else
            {array[high--] = array[low];break;}

    }
    array[low] = temp;
    return low;
}

int main(int argc,char** argv)
{
    long array[10] = {83,86,77,15,93,35,86,92,49,21};
    int result[10] = {21,49,35,15,77,93,86,92,83,86};
    std::cout << "partition before: " << std::endl;
    for(int i=0;i<10;i++)
        std::cout << array[i] << "    ";
    std::cout << std::endl;

    int mid = part(array,0,9);
    std::cout << "mid: " << mid << std::endl;
    
    std::cout << "partition after: " << std::endl;
    for(int i=0;i<10;i++)
        std::cout << array[i] << "    ";
    std::cout << std::endl;

    return 0;
}
