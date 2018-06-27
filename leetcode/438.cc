#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    int map[26] = {0};
    for(size_t i=0;i<p.size();++i)
        ++map[p[i]-'a'];
    
    int left = 0,right = 0,slength = s.size(),plength = p.size();
    while(right < slength) {
        if(map[s[right++]-'a']-- >= 0)
            --plength;
        if(plength == 0)
            res.push_back(left);
        if(right - left == plength && map[s[left++]-'a']++ >= 0)
            ++plength;
    }
    return res;
}

int main(int argc,char** argv)
{
    vector<int> res = findAnagrams("cbaebabacd","abc");
    for(size_t i=0;i<res.size();i++)
        std::cout << res[i] << "    ";
    std::cout << std::endl;
    return 0;
}
