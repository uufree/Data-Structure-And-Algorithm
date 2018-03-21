/*************************************************************************
	> File Name: BTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月19日 星期一 21时45分19秒
 ************************************************************************/

#ifndef _BTREE_H
#define _BTREE_H

#include"../2/vector.h"

template<typename T>
struct BTreeNode
{
    BTreeNode<T>* _parent;
    Vector<T> _key;
    Vector<BTreeNode<T>*> _child; 
    BTreeNode(){_parent = NULL;_child.insert(0,NULL);};
    BTreeNode(T elem,BTreeNode<T>* leftChild = NULL,BTreeNode<T>* rightChild = NULL)
    {
        _parent = NULL;
        _key.insert(elem);
        _child.insert(leftChild);
        _child.insert(rightChild);
        
        if(leftChild)
            leftChild->_parent = this;
        if(rightChild)
            rightChild->_parent = this;
    }
};

template<typename T>
class BTree 
{
    public:
        BTree(int order = 3) : _size(0),_order(order){_root = new BTreeNode<T>();}
        ~BTree(){delete _root;};
        int order() const{return _order;};
        int size() const{return _size;};
        BTreeNode<T>* root() const{return _root;};
        bool empty() const {return !_root;};
        BTreeNode<T>* search(T const& elem);
        bool remove(T const& elem);
        bool insert(T const& elem);

    protected:
        int _size;
        int _order;
        BTreeNode<T>* _root;
        BTreeNode<T>* _hot;
        void sloveOverFlow(BTreeNode<T>* node);//处理上溢
        void sloveUndreFlow(BTreeNode<T>* node);//处理下溢
};


#endif
