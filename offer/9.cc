/*************************************************************************
	> File Name: 9.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月06日 星期日 05时56分26秒
 ************************************************************************/

#include<iostream>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right; 
};

/////////////////////////////////////////
//27
void midOrder(BinaryTreeNode* node)
{
    if(node)
    {
        midOrder(node->left);
        std::cout << node->value << "    ";
        midOrder(node->right);
    }
}

void mirror(BinaryTreeNode* node)
{
    if(node == NULL)
        return;
    if(node->left == NULL && node->right == NULL)
        return;
    
    std::swap(node->left,node->right);
    
    if(node->left)
        mirror(node->left);
    if(node->right)
        mirror(node->right);
}

////////////////////////////////////////////
//28
bool isSymmetryCore(BinaryTreeNode* left,BinaryTreeNode* right)
{
    if(left == NULL && right == NULL)
        return true;
    if(left == NULL && right != NULL)
        return false;
    if(left != NULL && right == NULL)
        return false;
    
    if(left->value != right->value)
        return false;

    return isSymmetryCore(left->left,right->right) && isSymmetryCore(left->right,right->left);
}

bool isSymmetry(BinaryTreeNode* node)
{
    if(node == NULL)
        return false;
    return isSymmetryCore(node->left,node->right);
}

////////////////////////////////////
//29
void printMatrixCore(int (*mirtix)[4],int rows,int columns,int startRow,int startCol)
{
    if(rows <= 0 || columns <= 0 || startRow < 0 || startCol < 0)
        return;
    
    std::cout << "rows: " << rows << std::endl;
    std::cout << "columns: " << columns << std::endl;
    std::cout << "rowStart: " << startRow << std::endl;
    std::cout << "colStart: " << startCol << std::endl;
    
    
    if(rows == 1)
    {
        for(int i=0;i<columns;i++)
            std::cout << mirtix[startRow][startCol+i] << "    ";
        std::cout << std::endl;
        return;
    }

    if(columns == 1)
    {
        for(int i=0;i<rows;i++)
            std::cout << mirtix[startRow+i][startCol] << "    ";
        std::cout << std::endl;
        return;
    }

    for(int i=0;i<columns-1;i++)
        std::cout << mirtix[startRow][startCol+i] << "    ";
    for(int i=0;i<rows - 1;i++)
        std::cout << mirtix[startRow+i][startCol+columns-1] << "    ";
    for(int i=columns-1;i>=1;i--)
        std::cout << mirtix[startRow+rows-1][startCol+i] << "    ";
    for(int i=rows-1;i>=1;i--)
        std::cout << mirtix[startRow+i][startCol] << "    ";
    std::cout << std::endl;

    printMatrixCore(mirtix,rows-2,columns-2,startRow+1,startCol+1);
}

void printMatrix(int (*array)[4],int rows,int columns)
{
    if(array == NULL || rows <= 0 || columns == 0)
        return;
    printMatrixCore(array,rows,columns,0,0); 
}


int main(int argc,char** argv)
{
    struct BinaryTreeNode* nodeArray = new BinaryTreeNode[8];
    for(int i=0;i<8;i++)
        nodeArray[i].value = i;

    nodeArray[0].left = &nodeArray[1];
    nodeArray[0].right = &nodeArray[2];
    nodeArray[1].left = &nodeArray[3];
    nodeArray[1].right = NULL;
    nodeArray[2].left = &nodeArray[4];
    nodeArray[2].right = &nodeArray[5];
    nodeArray[3].left = NULL;
    nodeArray[3].right = &nodeArray[6];
    nodeArray[4].left = NULL;
    nodeArray[4].right = NULL;
    nodeArray[5].left = &nodeArray[7];
    nodeArray[5].right = NULL;
    nodeArray[6].left = NULL;
    nodeArray[6].right = NULL;
    nodeArray[7].left = NULL;
    nodeArray[7].right = NULL;
    
    int array[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printMatrix(array,3,4);

    return 0;
}
