/*************************************************************************
	> File Name: mergeSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月20日 星期三 19时06分06秒
 ************************************************************************/

#include<iostream>

void merge(int* array,int p,int q,int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* array1 = new int[n1+1];
    int* array2 = new int[n2+1];

    for(int i=0;i<n1;++i)
        array1[i] = array[p+i];

    for(int j=0;j<n2;++j)
        array2[j] = array[q+j+1];

    array1[n1] = array2[n2] = 99999;
/*    
    for(int i=0;i<6;++i)
        std::cout << array1[i] << std::endl;
    for(int i=0;i<6;++i)
        std::cout << array2[i] << std::endl;
*/    
    int i = 0,j = 0;
    for(;p<=r;++p)
    {
        if(array1[i] <= array2[j])
        {
            array[p] = array1[i];
            ++i;
        }
        else
        {
            array[p] = array2[j];
            ++j;
        }
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
       mergeSort(array,q+1,r);
       merge(array,p,q,r);
   }
}

int main(int argc,char** argv)
{
    int array[10] = {9,0,2,6,2,8,5,1,0,3};
    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    mergeSort(array,0,9);
    
//    merge(array,0,4,9);

    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    
    return 0;
}

































