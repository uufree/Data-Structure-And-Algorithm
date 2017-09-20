/*************************************************************************
	> File Name: insertSort.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月20日 星期三 18时28分32秒
 ************************************************************************/

#include<iostream>

int main(int argc,char** argv)
{
    int array[10] = {9,8,5,1,0,8,4,9,3,1};
    
    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
    
    for(int j=1;j<10;++j)
    {
        int temp = array[j];
        int i = j - 1;

        while(i >= 0 && array[i] < temp)//升序or降序仅需修改此处
        {
            array[i+1] = array[i];
            i = i - 1;
        }
        array[i+1] = temp;
    }
    
    for(int i=0;i<10;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    return 0;
}
