/*************************************************************************
	> File Name: 204.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月23日 星期六 09时54分15秒
 ************************************************************************/

#include<iostream>
#include<cmath>

int countPrimes(int n)
{
    if(n < 2)
        return 0;
    int pow = 0;
    int res = 0;
    bool isPri = true;
    for(int i=2;i<n;i++){
        pow = sqrt(i);
        while(pow > 1){
            if(i%pow == 0){
                isPri = false;
                break;
            }
            --pow;
        }
        if(isPri)
            ++res;
        isPri = true; 
    }
    return res;
}

int main(int argc,char** argv)
{
    std::cout << countPrimes(10) << std::endl; 
}
