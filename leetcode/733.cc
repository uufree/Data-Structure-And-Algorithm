/*************************************************************************
	> File Name: 733.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月25日 星期一 09时00分32秒
 ************************************************************************/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> res = image;
        queue<pair<int,int>> queue;
        queue.push({sr,sc});
        pair<int,int> temp;
        while(!queue.empty()) {
            temp = queue.front();
            queue.pop();
            res[temp.first][temp.second] = newColor;
            std::cout << queue.size() << std::endl;
            if((temp.first-1 > 0 && temp.second > 0) && (temp.first-1 < image[0].size()-1 && temp.second > 0))
                queue.push({temp.first-1,temp.second});
            if((temp.first > 0 && temp.second-1 > 0) && (temp.first < image[0].size()-1 && temp.second-1 > 0))
                queue.push({temp.first,temp.second-1});
            if((temp.first+1 > 0 && temp.second > 0) && (temp.first+1 < image[0].size()-1 && temp.second > 0))
                queue.push({temp.first+1,temp.second});
            if((temp.first > 0 && temp.second+1 > 0) && (temp.first-1 < image[0].size()-1 && temp.second+1 > 0))
                queue.push({temp.first,temp.second+1});
        }
        return res;
    }

int main(int argc,char** argv)
{
    vector<vector<int>> vec{{1,1,1},{1,1,0},{1,0,1}}; 
    vector<vector<int>> res = floodFill(vec,1,1,2);
    for(size_t i=0;i<res.size();i++) {
        for(size_t j=0;j<res[i].size();j++) {
            std::cout << res[i][j] << "    ";
        }
        std::cout << std::endl;
    }
    return 0;
}
