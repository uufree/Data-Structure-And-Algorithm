/*************************************************************************
	> File Name: 4-2-1.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月06日 星期二 18时08分53秒
 ************************************************************************/

//使用递归法求解矩阵
//不好写哇..C语言原生的内存机制在这种递归面前就是个大坑...

#include<iostream>

struct matrix
{
    int* array;
};

struct matrix* recursionMatrix(struct matrix* matrixA,struct matrix* matrixB);

int main(int argc,char** argv)
{
    struct matrix* matrixA = new matrix[4];
    struct matrix* matrixB = new matrix[4];

    for(int i=0;i<4;i++)
    {
        matrixA[i].array = new int[4];
        matrixA[i].array = new int[4];

        for(int j=0;j<4;j++)
            matrixA[i].array[j] = matrixB[i].array[j] = 2;
    }
        
    struct matrix* matrixC = recursionMatrix(matrixA,matrixB);

    
    return 0;
}

struct matrix* recursionMatrix(struct matrix* matrixA,struct matrix* matrixB)
{
}
