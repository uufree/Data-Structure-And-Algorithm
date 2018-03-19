/*************************************************************************
	> File Name: binarySearchTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月19日 星期一 17时37分06秒
 ************************************************************************/

#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include"../5/binaryTree.h"

template<typename K,typename V>
struct Entry
{
    K _key;V _value;
    Entry(K key = K(),V value = V()) : _key(key),_value(value){};
    Entry(Entry<K,V> const& entry) : _key(entry._key),_value(entry._value){};
    bool operator<(Entry<K,V> const& entry) const{return _key < entry._key;};
    bool operator>(Entry<K,V> const& entry) const{return _key > entry._key;};
    bool operator==(Entry<K,V> const& entry) const{return _key == entry._key;};
    bool operator!=(Entry<K,V> const& entry) const{return _key != entry._key;};
};

template<typename T>
class BinarySearchTree : public BinaryTree<T>
{
    protected:
        BinaryNode<T>* _hot;//当前节点的父节点
        BinaryNode<T>* connect34(BinaryNode<T>*,BinaryNode<T>*,BinaryNode<T>*,BinaryNode<T>*,BinaryNode<T>*,BinaryNode<T>*,BinaryNode<T>*);
        BinaryNode<T>* rotateAt(BinaryNode<T>* node);

    public:
        virtual BinaryNode<T>*& search(T const& elem);
        virtual BinaryNode<T>* insert(T const& elem);
        virtual bool remove(T const& elem);
};

template<typename T>
static BinaryNode<T>*& searchIn(BinaryNode<T>*& node,T const& elem,BinaryNode<T>*& father)
{
    if(node & (*node->_data == elem)) 
        return node;
    father = node;
    return searchIn((*node->_data) < elem ? node->_leftChild : node->_rightChild,elem,node);
}

template<typename T>
BinaryNode<T>*& BinarySearchTree<T>::search(T const& elem)
{
    return searchIn(BinaryTree<T>::_root,elem,_hot=NULL);
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::insert(T const& elem)
{
    BinaryNode<T>* node = search(elem);
    if(node)
        return node;
    
    node = new BinaryNode<T>(elem,_hot);
    BinaryTree<T>::_size++;
    BinaryTree<T>::updateHeightAbove(node);
    return node;
}

//这删除算法看的好迷啊...
template<typename T>
static BinaryNode<T>* removeAt(BinaryNode<T>*& node,BinaryNode<T>*& father)
{
    BinaryNode<T>* deleteNode = node;//实际被摘除的节点
    BinaryNode<T>* replaceNode = NULL;//实际被摘除节点的替代者
    
    if(!HasLeftChild(node))
        replaceNode = node = node->_rightChild;        
    else if(!HasRightChild(node))
        replaceNode = node = node->_leftChild;
    else
    {
        deleteNode = node->succ();
        std::swap(node->_data,deleteNode->_data);
        BinaryNode<T>* d_parent = deleteNode->_parent;
        ((d_parent == node) ? d_parent->_leftChild : d_parent->_rightChild) = replaceNode = deleteNode->_rightChild;     
    }
    
    father = deleteNode->_parent;
    if(replaceNode)
        replaceNode->_parent = father;
     
    release(deleteNode);
    return replaceNode;
}

template<typename T>
bool BinarySearchTree<T>::remove(T const& elem)
{
    BinaryNode<T>*& node = search(elem);
    if(!node)
        return false;
    removeAt(node,_hot);
    updateHeightAbove(_hot);
    return true;
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::connect34(BinaryNode<T>* a,BinaryNode<T>* b,BinaryNode<T>* c,BinaryNode<T>* T0,BinaryNode<T>* T1,BinaryNode<T>* T2,BinaryNode<T>* T3)
{
    a->_leftChild = T0;if(T0) T0->_parent = a;
    a->_rightChild = T1;if(T1) T1->_parent = a;
    c->_leftChild = T2;if(T2) T2->_parent = c;
    c->_rightChild = T3;if(T2) T2->_parent = c;
    b->_leftChild = a;a->_parent = b;
    b->_rightChild = c;c->_parent = b;
    updateHeightAbove(b);
}

template<typename T>
BinaryNode<T>* BinarySearchTree<T>::rotateAt(BinaryNode<T>* v)
{
    BinaryNode<T>* p = v->_parent;
    BinaryNode<T>* g = p->_parent;
    
    if(IsLeftChild(p))
    {
        if(IsLeftChild(v))
        {
            p->_parent = g->_parent;
            connect34(v,p,g,v->_leftChild,v->_rightChild,p->_rightChild,g->_rightChild);
        }
        else
        {
            v->_parent = g->_parent;
            connect34(p,v,g,p->_leftChild,v->_leftChild,v->_rightChild,g->_rightChild);
        }
    }
    else
    {
        if(IsLeftChild(v))
        {
            v->_parent = g->_parent;
            connect34(g,v,p,g->_leftChild,v->_leftChild,v->_rightChild,p->_rightChild);
        }
        else
        {
            p->_parent = g->_parent;
            connect34(g,p,v,g->_leftChild,p->_leftChild,v->_leftChild,v->_rightChild); 
        }
    }
}

#endif

