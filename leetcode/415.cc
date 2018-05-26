/*************************************************************************
	> File Name: 415.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月25日 星期五 19时56分03秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstring>

std::string addString(const std::string& num1,const std::string& num2)
{
    int size1 = num1.size();
    int size2 = num2.size();
    int size = size1 >= size2 ? size1 : size2;
    char res[size+1];
    memset(res,'\0',size+1);
    
    int n,m,add;
    int earn = 0;
    for(int i=1;i<=size;i++)
    {
        if(size1 >= i && size2 >= i)
        {
            n = num1[size1-i] - '0';
            m = num2[size2-i] - '0';
        }
        else
        {
            if(i > size1)
                n = 0;
            else
                n = num1[size1-i] - '0';
            
            if(i > size2)
                m = 0;
            else
                m = num2[size2-i] - '0';
            
        }
        
        add = n + m;
        
        int xx = add % 10;   //获得本次计算的个位数
        if(earn)    //上次有十位数保留
        {
            int both = xx + earn;   //获得本次计算的个位数与上次保留的十位数（在本次计算中，这个十位数当做个位数使用）
            if(both < 10)
                earn = 0;
            else
                earn = both / 10; 
            res[size-i+1] = both % 10 + '0';
        }
        else    //上次无十位数保留
            res[size-i+1] = xx + '0';
        earn = earn + add / 10;  //获得本次计算的十位数
    }
    
    if(earn)
        res[0] = earn + '0';
    
    std::string str;
    int i = 0;
    if(res[0] == '0')
        i = 1;

    for(;i<size+1;i++)
        str.push_back(res[i]);;
    return str;
}

int main(int argc,char** argv)
{
    std::cout << addString("123456789","987654321") << std::endl;
    return 0;
}

