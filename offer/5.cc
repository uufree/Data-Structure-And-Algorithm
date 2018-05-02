/*************************************************************************
	> File Name: 5.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月01日 星期二 18时10分15秒
 ************************************************************************/

#include<iostream>
#include<cstring>

////////////////////////////////////////////////////////
//12
bool hasPathCore(const char* matrix,int rows,int columns,int rowStart,int columnStart,bool* visited,const char* str,int strLength)
{
    if(str[strLength] == '\0')
        return true;
    bool hasPath = false;
    if(rowStart >= 0 && rowStart < rows && columnStart >= 0 && columnStart < columns && !visited[rowStart*columns + columnStart] && str[strLength] == matrix[rowStart*columns+columnStart])
    {
        ++strLength;
        visited[rowStart*columns + columnStart] = true;
        hasPath = hasPathCore(matrix,rows,columns,rowStart+1,columnStart,visited,str,strLength) || 
            hasPathCore(matrix,rows,columns,rowStart,columnStart+1,visited,str,strLength) || 
            hasPathCore(matrix,rows,columns,rowStart-1,columnStart,visited,str,strLength) || 
            hasPathCore(matrix,rows,columns,rowStart,columnStart-1,visited,str,strLength); 
        
        if(!hasPath)
        {
            --strLength;
            visited[rowStart*columns + columnStart] = false;
        }
    }
    return hasPath;
}

bool hasPath(const char* matrix,int rows,int columns,const char* str)
{
    if(matrix == NULL || rows <= 0 || columns <= 0 || str == NULL)
        return false;
    
    bool visited[rows * columns];
    memset(visited,0,rows*columns);
    int strLength = 0;
    for(int row=0;row<rows;row++)
        for(int column=0;column<columns;column++)
            if(hasPathCore(matrix,rows,columns,row,column,visited,str,strLength))
                return true;
    return false;
}

///////////////////////////////////////////////////////////
//13
bool isVailed(int number,int row,int column)
{
    int sum = 0;
    while(row > 0)
    {
        sum += row % 10;
        row /= 10;
    }

    while(column > 0)
    {
        sum += column % 10;
        column /= 10;
    }

    return sum != number ? true : false;
}

int moveCountCore(int number,int rows,int columns,int row,int column,bool* visited)
{
    int count = 0;
    if(row >= 0 && row < rows && column >= 0 && column < columns && !visited[columns*row + column] && isVailed(number,row,column))
    {
        visited[columns*row + column] = true;
        count = 1 + moveCountCore(number,rows,columns,row+1,column,visited) + 
            moveCountCore(number,rows,columns,row,column+1,visited) + 
            moveCountCore(number,rows,columns,row-1,column,visited) + 
            moveCountCore(number,rows,columns,row,column-1,visited);
    }
    return count;
}

int moveCount(int number,int rows,int columns)
{
    if(number < 0 || rows < 0 || columns < 0)
        return -1;
    bool visited[rows * columns];
    memset(visited,0,rows*columns);
    return moveCountCore(number,rows,columns,0,0,visited);
}

/////////////////////////////////////////
//14

int getSum(int length)
{
    if(length < 0)
        return -1;
    if(length == 1)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;
    
    int array[length+1];
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    array[3] = 3;
    
    for(int i=4;i<=length;i++)
    {
        int max = 0;
        for(int j = i/2;j>=0;j--)
        {
            int temp = array[j] * array[i-j];
            if(temp > max)
                max = temp;
        }
        array[i] = max;
    }
    
    return array[length];
}

//////////////////////////////////////
//15
int getBits1(int n)
{
    int count = 0;
    int temp = 0x0001;
    for(int i=0;i<32;i++)
    {
        if(temp & n)
            ++count;
        temp <<= 1;
    }
    return count;
}


int main(int argc,char** argv)
{
    std::cout << getBits1(-1) << std::endl;
    return 0;
}
