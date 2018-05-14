/*************************************************************************
	> File Name: 17.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月13日 星期日 06时39分20秒
 ************************************************************************/

#include<iostream>
#include<cstring>

//////////////////////////////////////
//58
void reverse(char* data,int length)
{
    char* start = data;
    char* end = data + length - 1;

    while(start < end)
    {
        std::swap(*start,*end);
        ++start;
        --end;
    }

    start = data;
    for(int i=0;i<length;i++)
    {
        if(data[i] == ' ')
        {
            end = data + i - 1;
            while(start < end)
            {
                std::swap(*start,*end);
                ++start;
                --end;
            }
            start = data + i + 1;
        }
    }
    std::cout << data << std::endl;
}

int main(int argc,char** argv)
{
    char data[15] = {'I',' ','a','m',' ','a',' ','s','t','u','d','e','n','t','.'};
    reverse(data,15);
    return 0;
}
