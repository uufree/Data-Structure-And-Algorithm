/*************************************************************************
	> File Name: 482.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月26日 星期二 21时19分38秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
string licenseKeyFormatting(string S, int K) {
        int length = S.size();
        for(int i=0;i<length;i++) {
            if(S[i] >= 'a' && S[i] <= 'z')
                S[i] -= 32;
        }   
        
        int start = 0,end = 0;
        for(int i=0;i<length;i++) {
            if
        }

        int k = K;
        string res;
        for(int i=S.length()-1;i>=0;i--) {
            --k;
            if(k == 0) {
                res = "-" + S.substr(i,K) + res;
                k = K;
            }
        }
        if(k != 0) {
            res = "-" + S.substr(0,k) + res;
        }
        return res.erase(0,1);
    }

int main() 
{
    std::cout << licenseKeyFormatting("a-a-a-a-",1) << std::endl;
}
