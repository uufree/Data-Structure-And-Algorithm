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

void prevOrder_r(struct BinaryTreeNode* node)
{
    std::stack<BinaryTreeNode*> stack;
    stack.push(node);

    while(!stack.empty())
    {
        struct BinaryTreeNode* temp = stack.top();
        stack.pop();
        std::cout << temp->value << std::endl;

        if(temp->right)
            stack.push(temp->right);
        if(temp->left)
            stack.push(temp->left);
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

void midOrder_r(struct BinaryTreeNode* node)
{
    std::stack<BinaryTreeNode*> stack;
    while(1)
    {
        while(node)
        {
            stack.push(node);
            node = node->left;
        }
        
        if(stack.empty())
            break;

        node = stack.top();
        stack.pop();
        std::cout << node->value << std::endl;
        node = node->right;
        
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

/////////////////////////////////////////////
//54
void midOrder_rs(BinaryTreeNode* node,int index)
{
    std::stack<BinaryTreeNode*> stack;

    while(1)
    {
        while(node)
        {
            stack.push(node);
            node = node->left;
        }

        if(stack.empty())
            break;
        --index;
        node = stack.top();
        stack.pop();
        if(index == 0)
        {
            std::cout << node->value << std::endl;
            break;
        }
        node = node->right;
    }
}

///////////////////////////////////////////
//55-01

int deepth(BinaryTreeNode* node)
{
    if(node == NULL)
        return 0;
    int left = deepth(node->left);
    int right = deepth(node->right);

    return left > right ? left+1 : right + 1;
}

///////////////////////////////////////
//55-02

bool isBlanced(BinaryTreeNode* node,int* deepth)
{
    if(node == NULL)
    {
        deepth = 0;
        return true;
    }
    
    int left;
    int right;
    if(isBlanced(node->left,&left) && isBlanced(node->right,&right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *deepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

bool isBlanced(BinaryTreeNode* node)
{
    if(node == NULL)
        return false;
    int deepth = 0;
    return isBlanced(node,&deepth);
}

//////////////////////////////////////////
//56-01
//利用异或的性质求只出现一次的数字

//////////////////////////////////////////
//57

void findPair(int* array,int length,int key)
{
    if(array == NULL || length <= 0)
        return;

    int* start = array;
    int* end = array+length-1;

    while(start < end)
    {
        if(*start + *end < key)
            ++head;
        else if(*start + *end == key)
        {
            std::cout << *start << "    " << *end << std::endl;
            break;
        }
        else
            --end;
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
    
    int arrays[8] = {1,2,3,4,5,6,7,8};
    findPair(arrays,8,7);
    return 0;
}
