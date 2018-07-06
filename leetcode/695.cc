/*************************************************************************
	> File Name: 695.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月27日 星期三 16时11分21秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int calculate(vector<vector<int>>& grid,int rowLength,int colLength,int row,int col) {
        if(row>=rowLength || row<0 || col>=colLength || col<0)
            return 0;
        if(grid[row][col]==0)
            return 0;
        grid[row][col] = 0;
        return 1+calculate(grid,rowLength,colLength,row,col+1) + 
            calculate(grid,rowLength,colLength,row+1,col) + 
            calculate(grid,rowLength,colLength,row,col-1) + 
            calculate(grid,rowLength,colLength,row-1,col);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rowLength = grid.size(),colLength = grid[0].size();
        int max = 0,current = 0;
        for(int i=0;i<rowLength;i++) {
            for(int j=0;j<colLength;j++) {
                if(grid[i][j])
                    current = calculate(grid,rowLength,colLength,i,j);
                if(current > max)
                    max = current;
                std::cout << current << "    " << max << std::endl;
            }
        }
        return max;
    }

int main()
{
    vector<vector<int>> vec{{0,0,1,0,0,0,0,1,0,0,0,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,1,1,0,1,0,0,0,0,0,0,0,0},
                            {0,1,0,0,1,1,0,0,1,0,1,0,0},
                            {0,1,0,0,1,1,0,0,1,1,1,0,0},
                            {0,0,0,0,0,0,0,0,0,0,1,0,0},
                            {0,0,0,0,0,0,0,1,1,1,0,0,0},
                            {0,0,0,0,0,0,0,1,1,0,0,0,0}
                        };
    std::cout << maxAreaOfIsland(vec) << std::endl;
    return 0;
}
