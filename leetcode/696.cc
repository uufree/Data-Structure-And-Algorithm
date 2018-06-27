/*************************************************************************
	> File Name: 696.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月23日 星期六 09时16分48秒
 ************************************************************************/

#include<iostream>
#include<string>

int countBinarySubstrings(std::string s) 
{
    int length = s.size();
    int number = 0;
    char ch = '2',ser = '2';
    int res = 0;
        
    for(int i=0;i<length;i++)
    {
        if(ch == '2')
            ch = s[i];
          
        if(s[i] == ch)
            ++number;
        else
        {
            std::cout << "length: " << number << std::endl;
            if(ch == '0')
                ser = '1';
            else
                ser = '0';
                
            for(int j = i+1;j<length;j++)
                if(s[j] == ser)
                    --number;
            if(number == 0)
                ++res;
            number = 0;
            ch = '2';
        }
    }
    return res;
}

int main(int argc,char** argv)
{
    std::cout << countBinarySubstrings("00110011") << std::endl;
    return 0;
}

