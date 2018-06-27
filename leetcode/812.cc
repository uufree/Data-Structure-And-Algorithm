/*************************************************************************
	> File Name: 812.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月26日 星期二 11时36分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;
double largestTriangleArea(vector<vector<int>>& points) {
        double xMin = 100,xMax = 0,yMin = 100,yMax = 0;
        int length = points.size();
        vector<int> a{100,0},b{0,0},c{0,0};
        for(int i=0;i<length;i++) {
            if(points[i][0]>xMax) xMax = points[i][0];                
            if(points[i][0]<xMin) xMin = points[i][0];
            if(points[i][1]>yMax) yMax = points[i][1];
            if(points[i][1]<yMin) yMin = points[i][1];
            if(points[i][0]<=a[0] && points[i][1]<=a[1]) a = points[i];
            if(points[i][0]>=c[0] && points[i][1]<=c[1]) c = points[i];
            if(points[i][0]>=b[0] && points[i][1]<=b[1]) b = points[i];
        }
        std::cout << "a0: " << a[0] << "    " << "a1: " << a[1] << std::endl;
        std::cout << "b0: " << b[0] << "    " << "b1: " << b[1] << std::endl;
        std::cout << "c0: " << c[0] << "    " << "c1: " << c[1] << std::endl;
        double ab = (double)abs((b[0]-a[0]))*abs((b[1]-a[1]))/2;
        double ac = (double)abs((c[0]-a[0]))*abs((c[1]-a[1]))/2;
        double bc = (double)abs((c[0]-b[0]))*abs((c[1]-b[1]))/2;
        std::cout << "ab: " << ab << "    " << "ac: " << ac << "    " << "bc: " << bc << std::endl;
        return (xMax-xMin)*(yMax-yMin)-ac-bc-ab;
    }

int main() 
{
    vector<vector<int>> vec{{10,7},{0,4},{5,7}};
    std::cout << largestTriangleArea(vec) << std::endl;
    return 0;
}
