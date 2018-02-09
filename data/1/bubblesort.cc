/*************************************************************************
	> File Name: bubblesort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月09日 星期五 15时26分20秒
 ************************************************************************/

//我去,我脑子生锈了???
#include<iostream>

int main(int argc,char** argv)
{
    int array[10] = {10,9,8,7,6,5,4,3,2,1};
    
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9-i;j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];;
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
    for(int i=0;i<10;i++)
        std::cout << array[i] << std::endl;

    return 0;
}

