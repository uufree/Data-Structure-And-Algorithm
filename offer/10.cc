/*************************************************************************
	> File Name: 10.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月07日 星期一 04时39分01秒
 ************************************************************************/

#include<iostream>
#include<queue>

struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

////////////////////////////////////////
//32
void levelOrder(BinaryTreeNode* node)
{
    if(node == NULL)
        return;
    std::queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(node);
    BinaryTreeNode* temp = NULL;

    while(!nodeQueue.empty())
    {
        temp = nodeQueue.front();
        nodeQueue.pop();
        std::cout << temp->value << "    ";
        if(temp->left)
            nodeQueue.push(temp->left);
        if(temp->right)
            nodeQueue.push(temp->right);
    }
}

void levelOrderWithSwitch(BinaryTreeNode* node)
{
    if(node == NULL)
        return;
    std::queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(node);
    BinaryTreeNode* temp = NULL;
    int currentLevel = 1;
    int nextLevel = 0;

    while(!nodeQueue.empty())
    {
        temp = nodeQueue.front();
        nodeQueue.pop();
        std::cout << temp->value << "    ";
        --currentLevel;
        
        if(temp->left)
        {
            nodeQueue.push(temp->left);
            ++nextLevel;
        }
        if(temp->right)
        {
            nodeQueue.push(temp->right);
            ++nextLevel;
        }
        
        if(currentLevel == 0)
        {
            std::cout << std::endl;
            std::swap(currentLevel,nextLevel);
        }
    }
}

void levelOrderWithBinary(BinaryTreeNode* node)
{
    if(node == NULL)
        return;
    std::queue<BinaryTreeNode*> nodeQueue;
    nodeQueue.push(node);
    BinaryTreeNode* temp = NULL;
    int currentLevel = 1;
    int nextLevel = 0;
    bool isSwitch = true;

    while(!nodeQueue.empty())
    {
        temp = nodeQueue.front();
        nodeQueue.pop();
        std::cout << temp->value << "    ";
        --currentLevel;
        
        if(isSwitch)
        {
            std::swap(temp->left,temp->right);
            isSwitch = false;
        }
        else
            isSwitch = true;

        if(temp->left)
        {
            nodeQueue.push(temp->left);
            ++nextLevel;
        }
        if(temp->right)
        {
            nodeQueue.push(temp->right);
            ++nextLevel;
        }
        
        if(currentLevel == 0)
        {
            std::cout << std::endl;
            std::swap(currentLevel,nextLevel);
        }
    }
}

///////////////////////////////////
//33
bool isPostOrder(int* array,int length)
{
    if(array == NULL || length <= 0)
        return false;
    
    int root = array[length - 1];
    int left = 0;
    int right = 0;

    for(;left<length-1;left++)
        if(array[left] > root)
            break;
    
    right = left;
    for(;right<length-1;right++)
        if(array[right] < root)
            return false;
    
    bool isLeft = true;
    bool isRight = true;
    if(left > 0)
        isLeft = isPostOrder(array,left);
    if(right<length-1)
        isRight = isPostOrder(array+left,length-1-left);

    return isLeft && isRight;
}

/////////////////////////////////
//34

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
    
    levelOrderWithBinary(&nodeArray[0]);
    std::cout << std::endl;

    return 0;
}
