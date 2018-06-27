/*************************************************************************
	> File Name: 28.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月25日 星期一 16时58分54秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
int strStr(string haystack, string needle) {
        if(needle.size() == 0)
            return 0;
        int length = haystack.size() - needle.size() + 1;
        int res = 0;
        for(int i=0;i<length;i++) {
            if(haystack[i] == needle[0]) {
                int j;
                for(j=0;j<needle.size();j++) {
                    if(haystack[i+j] != needle[j])
                        break;  
                }      
                
                if(j == needle.size()) {
                    res = i;
                    break;
                }
            }
        }
        return res;
    }

int main()
{
    std::cout << strStr("hello","ll") << std::endl;
    return 0;
}
