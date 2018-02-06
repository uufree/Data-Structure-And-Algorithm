/*************************************************************************
	> File Name: 4-2-0.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月06日 星期二 17时46分44秒
 ************************************************************************/

//暴力法求解矩阵

#include<iostream>

int main(int argc,char** argv)
{
    int matrixA[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int matrixB[3][3] = {{2,2,2},{2,2,2},{2,2,2}};
    int matrixC[3][3];

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int index = 0;
            for(int k=0;k<3;k++)
            {
                index = index + matrixA[i][k] * matrixB[k][j];
            }
            matrixC[i][j] = index;
        }
    }
    
    for(int i=0;i<3;i++)
        std::cout << matrixC[i][0] << "  " << matrixC[i][1] << "  " << matrixC[i][2] << std::endl; 

    return 0;
}

