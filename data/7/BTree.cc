/*************************************************************************
	> File Name: BTree.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月20日 星期二 22时07分27秒
 ************************************************************************/

#include<iostream>
#include"BTree.h"

template<typename T>
BTreeNode<T>* BTree<T>::search(T const& elem)
{
    BTreeNode<T>* s_node = _root;
    _hot = NULL;
    while(s_node)
    {
        int pos = s_node->_key.search(elem);
        if((pos >= 0) & (elem == s_node->_key[pos]))
            return s_node;
        _hot = s_node;
        s_node = s_node->_child[pos+1];
    }
    return NULL;
}

template<typename T>
bool BTree<T>::insert(T const& elem)
{
    BTreeNode<T>* node = search(elem);
    if(node)
        return false;
    int pos = _hot->_key.search(elem);
    _hot->_key.insert(pos+1,elem);
    _hot->_child.insert(pos+2,NULL);
    _size++;
    sloveOverFlow(_hot);
    return true;
}

template<typename T>
bool BTree<T>::remove(T const& elem)
{
    BTreeNode<T>* node = search(elem);
    if(!elem)
        return false;
}

//讲真,这个过程我特么没有看懂哎...
template<typename T>
void BTree<T>::sloveOverFlow(BTreeNode<T>* node)
{
    if(node->_child.size() <= _order)
        return;
    int pos = node->_key().size() >> 1;
    BTreeNode<T>* newNode = new BTreeNode<T>();
    for(int i=0;i<_order-pos-1;i++)
    {
        newNode->_key.insert(i,node->_key.remove(pos+1));
        newNode->_child.insert(i,node->_child.remove(pos+1));
    }
    newNode->_child[_order-pos-1] = node->_child.remove(pos+1);

    if(newNode->_child[0])
        for(int i=0;i<_order-pos;i++)
            newNode->_child[i]->_parent = node;
    
    BTreeNode<T>* parent = node->_parent;
    if(!parent)
    {
        _root = parent = new BTreeNode<T>();
        parent->_child[0] = node;
        node->_parent = parent;
    }
    
    int rank = 1 + parent->_key.search(node->_key[0]);
    parent->_key.insert(rank,node->_key.remove(pos));
    parent->_child.insert(rank+1,newNode);
    newNode->_parent = parent;
    sloveOverFlow(parent);
}
