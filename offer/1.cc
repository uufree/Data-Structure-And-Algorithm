/*************************************************************************
	> File Name: 1.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年04月30日 星期一 17时30分38秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<unistd.h>
#include<cstddef>

struct BinaryTreeNode
{
    int value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

void preOrder(BinaryTreeNode* node)
{
    if(node != NULL)
    {
        std::cout << node->value << "    ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void preOrder_r(BinaryTreeNode* node)
{
    std::stack<BinaryTreeNode*> stack;
    stack.push(node);
    
    while(!stack.empty())
    {
        BinaryTreeNode* cnode = stack.top();
        stack.pop();
        std::cout << cnode->value << "    ";
        
        if(cnode->right)
            stack.push(cnode->right);
        if(cnode->left)
            stack.push(cnode->left);
    }
}

void midOrder(BinaryTreeNode* node)
{
    if(node != NULL)
    {
        midOrder(node->left);
        std::cout << node->value << "    ";
        midOrder(node->right);
    }
}

void midOrder_r(BinaryTreeNode* node)
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
        std::cout << node->value << "    ";
        node = node->right;

    }
}

void postOrder(BinaryTreeNode* node)
{
    if(node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->value << "    ";
    }
}

void postOrder_r(BinaryTreeNode* node)
{
    std::stack<BinaryTreeNode*> stack;;
    stack.push(node);
    while(!stack.empty())
    {
        if(stack.top()->left != node && stack.top()->right != node)     //stack.top() != node->parent,这块的只要目的是判断当前的node是否有兄弟，有的话，向兄弟一侧偏移；没有的话，说明top是node的父亲，且只有node一个孩子，直接弹出，向top的兄弟一侧偏移
        {
            while((node = stack.top()))
            {
                if(!node->left && !node->right)
                    break;
                if(node->right)
                    stack.push(node->right);
                if(node->left)
                    stack.push(node->left);
            }
        }

        node = stack.top();
        stack.pop();
        std::cout << node->value << "    ";
    }
}

BinaryTreeNode* buildTreeCore(int* preArray,int* midArray,int length)
{
    int number = *preArray;
    BinaryTreeNode* node = new BinaryTreeNode;
    node->left = node->right = NULL;
    node->value = number;
    
    if(length == 1)
        return node;

    int midIndex = 0;
    while(*(midArray+midIndex) != number)
        ++midIndex;

    if(midIndex > 0)
        node->left = buildTreeCore(preArray+1,midArray,midIndex);
    if(length - 1 - midIndex > 0)
    node->right = buildTreeCore(preArray+1+midIndex,midArray+1+midIndex,length-1-midIndex); 
    return node;
}

void buildTree(int* preArray,int* midArray,int length)
{
    if(preArray == NULL || midArray == NULL || length <= 0)
        return;
    
    BinaryTreeNode* node = buildTreeCore(preArray,midArray,length);
    preOrder(node);
    std::cout << std::endl;
    midOrder(node);
    std::cout << std::endl;
}

struct BinaryTreeNode2
{
    int value;
    struct BinaryTreeNode2* left;
    struct BinaryTreeNode2* right;
    struct BinaryTreeNode2* parent;
};

#define IsLeftChild(node) (node->parent->left ==  node)
#define IsRightChild(node) (node->parent->right == node)
#define HasLeftChile(node) (node->left)
#define HasRightChile(node) (node->right)
#define HasParent(node) (node->parent)

BinaryTreeNode2* findNode(BinaryTreeNode2* node)
{
    if(node == NULL)
        return NULL;
    
    BinaryTreeNode2* cnode = NULL;
    if(HasRightChile(node))
    {
        node = node->right;
        while(node->left)
            node = node->left;
        cnode = node;
    }
    else
    {
        if(IsLeftChild(node))
           HasParent(node) ? cnode = node->parent : cnode = NULL;
        else
        {
            while(HasParent(node) && IsRightChild(node->parent))
                node = node->parent;
        }
    }
    return cnode;
}

std::stack<int> stack1;
std::stack<int> stack2;

void appendTail(int number)
{
    stack1.push(number);
}

int deleteHead()
{
    if(stack2.size() == 0)
    {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    int temp = -1;
    if(!stack2.empty())
    {
        temp = stack2.top();
        stack2.pop();
    }
    return temp;
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

/*    
    int preArray[8] = {1,2,4,7,3,5,6,8};
    int midArray[8] = {4,7,2,1,5,3,8,6};
    
    appendTail(1);
    appendTail(2);
    appendTail(3);
    appendTail(4);

    std::cout << deleteHead() << std::endl;
    std::cout << deleteHead() << std::endl;
    std::cout << deleteHead() << std::endl;
*/
    postOrder_r(&nodeArray[0]);
    std::cout << std::endl;
    return 0;
}

