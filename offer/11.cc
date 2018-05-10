/*************************************************************************
	> File Name: 11.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月09日 星期三 06时01分10秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void midOrder(BinaryTreeNode* node)
{
    if(node)
    {
        midOrder(node->left);
        std::cout << node->value << "    ";
        midOrder(node->right);
    }
}

//////////////////////////////////
//34
void printPath(std::vector<int>& stack)
{
    for(auto iter=stack.begin();iter!=stack.end();iter++)
        std::cout << *iter << "    ";
    std::cout << std::endl;
}

void findPathCore(BinaryTreeNode* node,int number,std::vector<int>& stack,int currentSum)
{
    stack.push_back(node->value);
    currentSum += node->value;    

    if(currentSum == number)
        if(node->left == NULL && node->right == NULL)
            printPath(stack);
    
    if(node->left && currentSum < number)
        findPathCore(node->left,number,stack,currentSum);
    if(node->right && currentSum < number)
        findPathCore(node->right,number,stack,currentSum);
    stack.pop_back();
}

void findPath(BinaryTreeNode* node,int number)
{
    if(node == NULL)
        return;

    std::vector<int> stack;
    int currentSum = 0;
    findPathCore(node,number,stack,currentSum);
}

/////////////////////////////////////////
//35
void serialize(BinaryTreeNode* node)
{
    if(node == NULL)
    {
        std::cout << "$" << "    ";
        return;
    }
    
    std::cout << node->value << "    ";
    serialize(node->left);
    serialize(node->right);
}

int main(int argc,char** argv)
{
    struct BinaryTreeNode* nodeArray = new BinaryTreeNode[8];
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
    for(int i=0;i<8;i++)
        nodeArray[i].value = i;
    
    serialize(&nodeArray[0]);
    std::cout << std::endl;
    return 0;
}
