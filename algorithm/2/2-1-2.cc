/*************************************************************************
	> File Name: 2-1-1.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月04日 星期日 17时08分54秒
 ************************************************************************/

#include<iostream>

int main(int argc,char** argv)
{
    int array[10] = {31,41,59,26,41,58,90,33,61,82};
    std::cout << "insert-sort-before: ";
    for(int i=0;i<10;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    
    for(int i=1;i<10;i++)
    {
        int number = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] < number)
        {
            array[j+1] = array[j];
            --j;
        }
        array[j+1] = number; 
    }
    
    std::cout << "insert-sort-after: ";
    for(int i=0;i<10;i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}

