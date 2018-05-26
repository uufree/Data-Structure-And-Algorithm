/*************************************************************************
	> File Name: 623.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月15日 星期二 16时52分09秒
 ************************************************************************/

#include<iostream>
#include<queue>
#include<vector>

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x),left(NULL),right(NULL){};
};

void midOrder(TreeNode* node)
{
    if(node)
    {
        midOrder(node->left);
        std::cout << node->val << "    ";
        midOrder(node->right);
    }
}

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
        return newNode;
    }
    std::queue<TreeNode*> queue;
    queue.push(root);
    int l = 1;
    while(!queue.empty())
    {
        int n = queue.size();
        while(n--)
        {
            TreeNode* node = queue.front();
            queue.pop();
            if(l == d-1)
            {
                TreeNode* newNode = new TreeNode(v);
                newNode->left = node->left;
                node->left = newNode;
                TreeNode* newNode1 = new TreeNode(v);
                newNode1->right = node->right;
                node->right = newNode1;
            }
            else
            {
                if(node->left)
                    queue.push(node->left);
                if(node->right)
                    queue.push(node->right);
            }
        }
        ++l;
    }
    return root;
}

int main(int argc,char** argv)
{
    TreeNode* array = new TreeNode[6]{4,2,6,3,1,5};
    array[0].left = &array[1];
    array[0].right = &array[2];
    array[1].left = &array[3];
    array[1].right = &array[4];
    array[2].left = &array[5];
    
//    addOneRow(&array[0],1,2);
    levelOrder(&array[0]);
    return 0;
}
