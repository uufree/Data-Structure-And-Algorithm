/*************************************************************************
	> File Name: 2-3-1.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月04日 星期日 21时39分29秒
 ************************************************************************/

#include<iostream>

void mergeSort(int* array,int low,int high);
void merge(int* array,int low,int mid,int high);

int main(int argc,char** argv)
{
    int array[10] = {3,41,52,26,38,57,9,49,10,28};
    std::cout << "merge-sort before: ";
    for(int i=0;i<10;i++)
        std::cout << array[i] << "  ";
    std::cout << std::endl;

    mergeSort(array,0,9);

    std::cout << "merge-sort after: ";
    for(int i=0;i<10;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}


void mergeSort(int* array,int low,int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(array,low,mid);
        mergeSort(array,mid+1,high);
        merge(array,low,mid,high);
    }
}

void merge(int* array,int low,int mid,int high)
{
    int lowLen = mid - low + 1;
    int highLen = high - mid;
    int* lowArray = new int[lowLen+1];
    int* highArray = new int[highLen+1];

    for(int i=0;i<lowLen;i++)
        lowArray[i] = array[low + i];
    lowArray[lowLen] = 9999;
    for(int i=0;i<highLen;i++)
        highArray[i] = array[mid + i + 1];
    highArray[highLen] = 9999;


    int lowIndex = 0,highIndex = 0;
    for(;low<=high;low++)
    {
        if(lowArray[lowIndex] < highArray[highIndex])
        {
            array[low] = lowArray[lowIndex];
            ++lowIndex;
        }
        else
        {
            array[low] = highArray[highIndex];
            ++highIndex;
        }
    }

    delete [] lowArray;
    delete [] highArray;
}
