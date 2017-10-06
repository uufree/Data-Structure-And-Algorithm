/*************************************************************************
	> File Name: mergeSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月20日 星期三 19时06分06秒
 ************************************************************************/

#include<iostream>

void merge(int* array,int p,int q,int r)
{
    int n1 = q - p; 
    int n2 = r - q;
    
    int* array1 = new int[n1];
    int* array2 = new int[n2];

    for(int i=0;i<n1;++i)
        array1[i] = array[p+i];

    for(int j=0;j<n2;++j)
        array2[j] = array[q+j];

    int i = 0,j = 0;
    for(;p<=r;++p)
    {
        if(i == n1 || j == n2)
            break;
        
        if(array1[i] <= array2[j])
        {
            array[p] = array1[i];
            i += 1;
        }
        else
        {
            array[p] = array2[j];
            j += 1;
        }
    }
    
    if(i == n1)
    {
        for(;j<n2;++j,++p)
            array[p] = array2[j];
    }

    if(j == n2)
    {
        for(;i<n1;++i,++p)
            array[p] = array1[i];
    }

    delete [] array1;
    delete [] array2;
}

void mergeSort(int* array,int p,int r)
{
   if(p < r)
   {
       int q = (p+r)/2;
       mergeSort(array,p,q);
       mergeSort(array,q,r);
       merge(array,p,q,r);
   }
}

int main(int argc,char** argv)
{
    int array[10] = {9,8,7,6,5,4,3,2,1,0};
    
    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    mergeSort(array,0,10);
//    merge(array,0,5,10);

    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    
    return 0;
}
