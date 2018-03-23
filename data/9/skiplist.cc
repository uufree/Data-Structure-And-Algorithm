/*************************************************************************
	> File Name: skiplist.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月23日 星期五 21时37分22秒
 ************************************************************************/

#include<iostream>
#include"skiplist.h"
#include<cstdlib>

template<typename T>
void QuadList<T>::init()
{
    _header->_pred = _tailer->_succ = NULL;
    _header->_succ = _tailer;
    _tailer->_pred = _header;
    _tailer->_above = _header->_above = NULL;
    _tailer->_below = _header->_below = NULL;
    _size = 0;
}

template<typename K,typename V>
bool SkipList<K,V>::skipSearch(ListNode<QuadList<Entry<K,V>>*>*& qlist,QuadListNode<Entry<K,V>>*& p,K& k)
{
    while(1)
    {
        while(p->_succ & (p->_entry._key <= k))
            p = p->_succ;
        p = p->_pred;
        if(p->_pred & (p->_entry._key == k))
            return true;
        qlist = qlist->_below;
        if(!qlist)
            return false;
        (p = p->_pred) ? p->_below : qlist->_data->first(); 
    }
}

template<typename K,typename V>
V* SkipList<K,V>::get(K key)
{
    if(List<QuadList<Entry<K,V>>*>::empty())
        return NULL;
    ListNode<QuadList<Entry<K,V>>*>* qlist = List<QuadList<Entry<K,V>>*>::first();
    QuadListNode<Entry<K,V>>* p = qlist->_data->first();
    return skipSearch(qlist,p,key);
}

template<typename K,typename V>
bool SkipList<K,V>::put(K key,V value)
{
    Entry<K,V> entry(key,value);
    if(List<QuadList<Entry<K,V>>*>::empty())
        insertAsSuccAbove(new QuadList<Entry<K,V>>);
    ListNode<QuadList<Entry<K,V>>*>* qlist = List<QuadList<Entry<K,V>>*>::first();
    QuadListNode<Entry<K,V>>* p = qlist->_data->first();
    if(skipSearch(qlist,p,key))
        while(p->_below)
            p = p->_below;
    qlist = List<QuadList<Entry<K,V>>*>::last(); 
    QuadListNode<Entry<K,V>>* newNode = qlist->_data->insertAsSuccAbove(entry,p,NULL);
    
    while(rand() % 2)
    {
        while(qlist->_data->vaild(p) && !p->_above) 
            p = p->_pred;
        if(!qlist->_data->vaild(p))
        {
            if(qlist == List<QuadList<Entry<K,V>>*>::first())
                insertAsSuccAbove(new QuadList<Entry<K,V>>);
            p = qlist->_pred->_data->first()->_pred;
        }
        else
            p = p->above;
        qlist = qlist->_prev;
        newNode = qlist->_data->insertAsSuccAbove(entry,p,newNode);
    }
    
    return true;
}

template<typename T>
QuadListNode<T>* QuadList<T>::insertAsSuccAbove(T const& elem,QuadListNode<T>* s_node,QuadListNode<T>* a_node)
{
    _size++;
    return s_node->insertAsSuccAbove(elem,a_node);
}

template<typename T>
QuadListNode<T>* QuadListNode<T>::insertAsSuccAbove(T const& elem,QuadListNode<T>* node)
{
    QuadListNode<T>* newNode = new QuadListNode<T>(elem,this,_succ,NULL,node);
    _succ->_pred = newNode;
    _succ = newNode;
    if(node)
        node->_above = newNode;
    return newNode;
}

template<typename K,typename V>
bool SkipList<K,V>::remove(K key)
{
    if(List<QuadList<Entry<K,V>>*>::empty())
        return false;
    ListNode<QuadList<Entry<K,V>>*>* qlist = List<QuadList<Entry<K,V>>*>::first();
    QuadListNode<Entry<K,V>>* p = qlist->_data->first();
    if(!skipSearch(qlist,p,key))
        return false;

    do
    {
        QuadListNode<Entry<K,V>>* lower = p->_below;
        qlist->_data->remove(p);
        p = lower;
        qlist = qlist->_next;
    }while(qlist->_next);
    
    while(!List<QuadList<Entry<K,V>>*>::empty())
        List<QuadList<Entry<K,V>>*>::remove(qlist->_data->fist());
    
    return true;
}

template<typename T>
T QuadList<T>::remove(QuadListNode<T>* p)
{
    p->_pred->_succ = p->_succ;
    p->_succ->_pred = p->_pred;
    _size--;
    T elem = p->_entry;
    delete p;
    return elem;
}

template<typename T>
int QuadList<T>::clear()
{
    int oldSize = _size;
    while(_size)
        remove(_header->_succ);
    return oldSize - _size;
}

