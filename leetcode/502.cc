/*************************************************************************
	> File Name: 502.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年06月24日 星期日 20时25分40秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_) : val(val_),left(nullptr),right(nullptr){};
};

void findMaxNum(TreeNode* root,int& maxNumber,int& maxTimes,int& lastNumber,int& lastTimes) {
        if(root == nullptr)
            return;
        findMaxNum(root->left,maxNumber,maxTimes,lastNumber,lastTimes);
        if(root->val == lastNumber) { 
            ++lastTimes;
        } else {
            lastNumber = root->val;
            lastTimes = 1;
        }
        
        if(lastTimes >= maxTimes) {
            maxNumber = root->val;
            maxTimes = lastTimes;
        }
        findMaxNum(root->right,maxNumber,maxTimes,lastNumber,lastTimes);
    }
    
    void findMaxNumCore(TreeNode* root,int& maxTimes,int& lastNumber,int& lastTimes,vector<int>& res) {
        if(root == nullptr)
            return;
        findMaxNumCore(root->left,maxTimes,lastNumber,lastTimes,res);
        if(root->val == lastNumber) {
            ++lastTimes;
        } else {
            lastNumber = root->val;
            lastTimes = 1;
        }
        if(lastTimes == maxTimes)
            res.push_back(root->val);
        findMaxNumCore(root->right,maxTimes,lastNumber,lastTimes,res);
    }
    
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if(root == nullptr)
            return res;
        int maxNumber = 0,maxTimes = 0,lastNumber = root->val,lastTimes = 0;
        findMaxNum(root,maxNumber,maxTimes,lastNumber,lastTimes);
        
        lastNumber = root->val;
        lastTimes = 0;
        findMaxNumCore(root,maxTimes,lastNumber,lastTimes,res);
        return res;
    }

int main(int argc,char** argv)
{
    TreeNode root(25536);

    vector<int> res = findMode(&root);
    for(size_t i=0;i<res.size();i++)
        std::cout << res[i] << "    ";
    std::cout << std::endl;
    return 0;
}
