/*************************************************************************
	> File Name: LinkedBinaryTreeTest.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年07月20日 星期四 10时45分30秒
 ************************************************************************/

#include<iostream>
#include"LinkedBinaryTree.h"
#include<vector>

void visit(BinaryTreeNode* node)
{std::cout << node->data << "  ";}


int main(int argc,char** argv)
{
    LinkedBinaryTree tree1;
    tree1.init();
    LinkedBinaryTree tree(tree1);

    std::cout << "preOrder: " << std::endl;
    tree.perOrder(std::bind(&visit,std::placeholders::_1));
    std::cout << std::endl;
    
    std::cout << "levelOrder: " << std::endl;
    tree.levelOrder(std::bind(&visit,std::placeholders::_1));
    std::cout << std::endl;

    std::cout << "postOrder: " << std::endl;
    tree.postOrder(std::bind(&visit,std::placeholders::_1));
    std::cout << std::endl;

    std::cout << "inOrder: " << std::endl;
    tree.inOrder(std::bind(&visit,std::placeholders::_1));
    std::cout << std::endl;
    
    std::cout << "heihght: " << tree.height() << std::endl;

    return 0; 
}
