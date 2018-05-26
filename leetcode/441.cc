/*************************************************************************
	> File Name: 441.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月26日 星期六 00时25分30秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

int coins(int num)
{
    if(num == 0)
        return 0;
    int level = 1;
    int res = 0;
    while(num > 0)
    {
        num -= level;
        level += 1;
        if(num >= 0)
            ++res;
    }
    return res;
}

int find(std::vector<int>& g,std::vector<int>& s)
{
    std::sort(g.begin(),g.end());
    std::sort(s.begin(),s.end());

    int gpos = 0;
    int gsize = g.size();
    int spos = 0;
    int ssize = s.size();
    int res = 0;

    while(gpos < gsize && spos < ssize)
    {
        if(s[spos] >= g[gpos])
        {
            ++gpos;
            ++spos;
            ++res;
        }
        else
            ++spos;
    }
    return res;
}

int main()
{
    std::vector<int> a{1,2};
    std::vector<int> b{1,2,3};
    std::cout << find(a,b) << std::endl;
    return 0;
}
