/*************************************************************************
	> File Name: binaryTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时03分39秒
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include<iostream>
#include<functional>


typedef enum{RB_RED,RB_BLACK} RBColor;

template<typename T>
struct BinaryNode
{
    T _data;
    BinaryNode<T>* _parent;
    BinaryNode<T>* _leftChild;
    BinaryNode<T>* _rightChild;
    int _hight;
    RBColor _color;

    BinaryNode() : 
        _data(T()),
        _parent(NULL),
        _leftChild(NULL),
        _rightChild(NULL),
        _hight(0),
        _color(RB_RED)
    {};

    BinaryNode(T data,BinaryNode<T>* parent = NULL,BinaryNode<T>* leftChild = NULL,BinaryNode<T>* rightChild = NULL,int hight = 0,RBColor color = RB_RED) :
        _data(data),
        _parent(parent),
        _leftChild(leftChild),
        _rightChild(rightChild),
        _hight(hight),
        _color(color)
    {};

    int size();
    BinaryNode<T>* insertAsLeftChild(T const& data);
    BinaryNode<T>* insertAsRightChild(T const& data);
    BinaryNode<T>* succ();//取当前节点的直接后继
    void travLevel();
    void travPre();
    void travIn();
    void travPost();

    bool operator==(BinaryNode const& node){return node._data == _data;};
    bool operator<(BinaryNode const& node){return _data < node._data;};
};

template<typename T>
class BinaryTree
{
    public:
        explicit BinaryTree() : _size(0),_root(NULL){};
        ~BinaryTree(){if(_size > 0) remove(_root);};
        
        int size() const {return _size;};
        bool empty() const {return !_root;};
        BinaryNode<T>* root() const {return _root;};
        BinaryNode<T>* insertAsRoot(T const& elem);
        BinaryNode<T>* insertAsLeftChild(BinaryNode<T>* node,T const& elem);
        BinaryNode<T>* insertAsRightChild(BinaryNode<T>* node,T const& elem);
        BinaryNode<T>* attachAsLeftChild(BinaryNode<T>* node,BinaryTree<T>* tree);
        BinaryNode<T>* attachAsRightChild(BinaryNode<T>* node,BinaryTree<T>* tree);
        int remove(BinaryNode<T>* node);
        BinaryTree<T>* secede(BinaryNode<T>* node);
        void travLevel() const {if(_root) _root->travLevel();};
        void travIn() const {if(_root) _root->travIn();};
        void travPost() const {if(_root) _root->travPost();};
        void travPre() const {if(_root) _root->travPre();};
        bool operator==(BinaryTree<T> const& tree) const {return _root == tree._root;};
        bool operator<(BinaryTree<T> const& tree) const {return _root < tree._root;};

    protected:
        int _size;
        BinaryNode<T>* _root;
        virtual int updateHeight(BinaryNode<T>* node);
        void updateHeightAbove(BinaryNode<T>* node);
};


#endif
