/*************************************************************************
	> File Name: 108.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年05月29日 星期二 02时27分05秒
 ************************************************************************/

#include<iostream>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int cal) : val(cal),left(NULL),right(NULL){};
};

TreeNode* buildTree(vector<int>& vec,int start,int end)
{
    if(start == end)
        return NULL;

    int mid = (start + end) >> 1;
    TreeNode* node = new TreeNode(vec[mid]);
    node->left = buildTree(vec,start,mid);
    node->right = buildTree(vec,mid+1,end);
    return node;
}

void midOrder(TreeNode* node)
{
    if(node)
    {
        midOrder(node->left);
        std::cout << node->val << std::endl;
        midOrder(node->right);
    }
}

int main(int argc,char** argv)
{
    vector<int> vec = {-10,-3,0,5,9};
    TreeNode* root = buildTree(vec,0,vec.size());
    midOrder(root);

    return 0;
}
