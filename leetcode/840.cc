/*************************************************************************
	> File Name: 840.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月27日 星期三 15时16分15秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
int numMagicSquaresInside(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size();
        vector<vector<int>> vec;
        int res = 0;
        for(int i=0;i<row-2;i++) {
            for(int j=0;j<col-2;j++) {
                vec.push_back({grid[i][j],grid[i][j+1],grid[i][j+2]});
                vec.push_back({grid[i+1][j],grid[i+1][j+1],grid[i+1][j+2]});
                vec.push_back({grid[i+2][j],grid[i+2][j+1],grid[i+2][j+2]});
                
                if(vec[0][0]+vec[0][1]+vec[0][2]==15 && vec[1][0]+vec[1][1]+vec[1][2]==15 && vec[2][0]+vec[2][1]+vec[2][2]==15 &&
              vec[0][0]+vec[1][0]+vec[2][0]==15 && vec[0][1]+vec[1][1]+vec[2][1]==15 && vec[0][2]+vec[1][2]+vec[2][2]==15 && 
              vec[0][0]+vec[1][1]+vec[2][2]==15 && vec[0][2]+vec[1][1]+vec[2][0]==15)
                    ++res;
                vec.clear();
            }
        }
        return res;
    }

int main()
{
    vector<vector<int>> vec{{4,3,8,4},{9,5,1,9},{2,7,6,2}};
    std::cout << numMagicSquaresInside(vec) << std::endl;
    return 0;
}
