/*************************************************************************
	> File Name: 1004.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月23日 星期六 20时53分48秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<complex>
#include<map>

typedef std::pair<std::string,std::string> strPair;

int main(int argc,char** argv)
{
    std::map<int,strPair> pairMap;
    std::vector<int> vec;

    std::string name,number;
    int size;
    std::string str;

    std::cin >> size;
    
    for(int i=0;i<size;++i)
    {
        std::cin >> str;
        

        if(name.size() > 10 || number.size() > 10 || size < 0 || size > 100)
            return 0;
        
        strPair papa{name,number};

        auto iter = std::find(vec.begin(),vec.end(),size);
        if(iter != vec.end())
            return 0;
        
        vec.push_back(size);
        pairMap.insert({size,papa});
    }
    
    auto iter = std::max_element(pairMap.begin(),pairMap.end());
    strPair str1 = iter->second;
    
    std::cout << str1.first << " " << str1.second;
    std::cout << std::endl;
    
    auto iter1 = std::min_element(pairMap.begin(),pairMap.end());
    strPair str2 = iter1->second;
    
    std::cout << str2.first << " " << str2.second;
    std::cout << std::endl;
    
    return 0;
}

