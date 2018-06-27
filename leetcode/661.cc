/*************************************************************************
	> File Name: 661.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月25日 星期一 15时33分45秒
 ************************************************************************/
#include<vector>
#include<iostream>
using namespace std;

int calculate(vector<vector<int>>& vec,int row,int col) {
        int cal = 1,rowLength = vec.size(),colLength = vec[0].size();
        int sum = vec[row][col];
        if(row-1>=0 && col-1>=0) {
            ++cal;
            sum += vec[row-1][col-1];
        }
        
        if(col-1>=0) {
            ++cal;
            sum += vec[row][col-1];
        }
        
        if(row+1<rowLength && col-1>=0) {
            ++cal;
            sum += vec[row+1][col-1];
        }
        
        if(row+1<rowLength) {
            ++cal;
            sum += vec[row+1][col];
        }
        
        if(row+1<rowLength && col+1<colLength) {
            ++cal;
            sum += vec[row+1][col+1];
        }
        
        if(col+1<colLength) {
            ++cal;
            sum += vec[row][col+1];
        }
        
        if(col+1<colLength && row-1>=0) {
            ++cal;
            sum += vec[row-1][col+1];
        }
        
        if(row-1>=0) {
            ++cal;
            sum += vec[row-1][col];
        }
        std::cout << "row: " << row << "    " << "col: " << col << "    " << "sum: " << sum << "    " << "cal: " << cal << "    " << "average: " << sum/cal << std::endl;
        return sum / cal;
    }
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> res;
        if(M.empty())
            return res;
        vector<int> temp;
        for(int i=0;i<M.size();i++) {
            for(int j=0;j<M[i].size();j++) {
                temp.push_back(calculate(M,i,j));
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }

int main(int argc,char** argv)
{
    vector<vector<int>> res{{2,3,4},{5,6,7},{8,9,10},{11,12,13},{14,15,16}};
    imageSmoother(res);
    return 0;
}
