/*************************************************************************
	> File Name: 16.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月13日 星期日 01时56分08秒
 ************************************************************************/

#include<iostream>
#include<stack>

struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

void prevOrder(struct BinaryTreeNode* node)
{
    if(node)
    {
        std::cout << node->value << std::endl;
        prevOrder(node->left);
        prevOrder(node->right);
    }
}

void midOrder(struct BinaryTreeNode* node)
{
    if(node)
    {
        midOrder(node->left);
        std::cout << node->value << std::endl;
        midOrder(node->right);
    }
}

void postOrder(struct BinaryTreeNode* node)
{
    if(node)
    {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->value << std::endl;
    }
}

int main(int argc,char** argv)
{
    struct BinaryTreeNode* array = new BinaryTreeNode[7];
    array[0].value = 5;
    array[0].left = &array[1];
    array[0].right = &array[2];
    array[1].value = 3;
    array[1].left = &array[3];
    array[1].right = &array[4];
    array[2].value = 7;
    array[2].left = &array[5];
    array[2].right = &array[6];
    array[3].value = 2;
    array[3].left = NULL;
    array[3].right = NULL;
    array[4].value = 4;
    array[4].left = NULL;
    array[4].right = NULL;
    array[5].value = 6;
    array[5].left = NULL;
    array[5].right = NULL;
    array[6].value = 8;
    array[6].left = NULL;
    array[6].right = NULL;

    midOrder(&array[0]);
    return 0;
}
