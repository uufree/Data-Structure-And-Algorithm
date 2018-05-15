/*************************************************************************
	> File Name: 623.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月15日 星期二 16时52分09秒
 ************************************************************************/

#include<iostream>
#include<queue>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
};

void levelOrder(TreeNode* node)
{
    std::queue<TreeNode*> queue;
    queue.push(node);
    TreeNode* temp = NULL;

    while(!queue.empty())
    {
        temp = queue.front();
        std::cout << temp->val << "  ";
        if(temp->left)
            queue.push(temp->left);
        if(temp->right)
            queue.push(temp->right);
    }
}

TreeNode* addOneRow(TreeNode* root,int v,int d)
{
    if(d == 1 && root->left == NULL && root->right == NULL)
    {
        TreeNode* newNode = new TreeNode(v);
        newNode->left = root;
    }
    
}
