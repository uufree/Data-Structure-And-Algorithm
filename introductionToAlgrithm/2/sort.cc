/*************************************************************************
	> File Name: sort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月22日 星期五 21时47分19秒
 ************************************************************************/

#include<iostream>

int main(int argc,char** argv)
{
    int array[10] = {9,8,7,6,5,4,3,2,1,0};

    for(int i=0;i<9;++i)
    {
        for(int j=i;j<10;++j)
        {
            if(array[i] >= array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for(int i=0;i<10;++i)
        std::cout << array[i] << std::endl;

    return 0;
}

