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
    
    int pos = node->_key.search(elem);
    if(node->_child[0])//判断node非叶子(内部节点),然后找到直接前继,交换并删除
    {
        BTreeNode<T>* p_node = node->_child[pos+1];
        while(p_node->_child[0])
            p_node = p_node->_child[0];
        node->_key[pos] = node->_key[0];
        node = p_node;
        pos = 0;
    }
    node->_key.remove(pos);
    node->_child.remove(pos+1);
    sloveUndreFlow(node);
    return true;
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

//说出来你可能不信...这个过程更难...
//B-树的这个过程我没有看懂...先留着不写,等写STL的时候详细研究,还需要再修炼哇...
template<typename T>
void BTree<T>::sloveUndreFlow(BTreeNode<T>* node)
{
}
