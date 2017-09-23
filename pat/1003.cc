/*************************************************************************
	> File Name: 1003.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月23日 星期六 20时53分42秒
 ************************************************************************/
//用正则吧，逻辑好点

#include<iostream>
#include<vector>
#include<string>

int main(int argc,char** argv)
{
    std::vector<std::string> strVec;
    int number;
    std::cin >> number;
    
    if(number >= 10)
        return 0;

    std::string str;
    for(int i = 0;i<number;++i)
    {
        std::cin >> str;
        if(str.size() > 100 || str == " ")
            return 0;
        
        strVec.push_back(str);
    }
    
    for(int i=0;i<number;++i)
    {
        str = strVec[i];
        
        for(size_t i=0;i<str.size();++i)
        {
            if(str[i] == 'A')
                continue;
            else if(str[i] == 'P')
            {
                ++i;
                for(;i<str.size();++i)
                {
                    if(str[i] == 'A')
                        continue;
                    else if(str[i] == 'T')
                    {
                        ++i;
                        for(;i<str.size();++i)
                        {
                            if(str[i] != 'A')
                            {
                                std::cout << "NO";
                                goto read;
                            }
                        }

                        std::cout << "YES";
                        goto read;
                    }
                    else
                    {
                        std::cout << "NO";
                        goto read;
                    }
                }
            }
            else
            {
                std::cout << "NO";
                goto read;
            };
        }
read:
        std::cout << std::endl;
    }
    
    return 0;
}
