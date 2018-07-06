/*************************************************************************
	> File Name: 849.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月27日 星期三 16时55分10秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int maxDistToClosest(vector<int>& seats) {
        int length = seats.size(),oneone = 0,onetwo = 0,zeropos = 0;
        int current = 0,max = 0;
        for(int i=0;i<length;i++) { 
            if(seats[i]==1) {
                oneone = i;
                continue;
            } else {
                zeropos = i;
                for(onetwo=i+1;onetwo<length;onetwo++)
                    if(seats[onetwo]==1)
                        break;
                if(onetwo != length)
                    current = zeropos-oneone < onetwo-zeropos ? zeropos-oneone : onetwo-zeropos;
                else
                    current = length-1-oneone;
                std::cout << "oneone: " << oneone << "    " << "onetwo: " << onetwo  << "    " << "zeropos: " << zeropos << "    ";
                std::cout << "current: " << current << "    " << "max: " << max << std::endl;
                if(current > max)
                    max = current;
            }
        }
        return max;
    }

int main()
{
    vector<int> vec{1,0,0,0};
    std::cout << maxDistToClosest(vec) << std::endl;
    return 0;
}
