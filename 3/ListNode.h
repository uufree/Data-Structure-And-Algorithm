/*************************************************************************
	> File Name: ListNode.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 20时04分06秒
 ************************************************************************/

#ifndef _LISTNODE_H
#define _LISTNODE_H

template<typename T>
struct ListNode
{
    T _data;
    ListNode<T>* _prev;
    ListNode<T>* _next;
    
    ListNode(){};
    ListNode(const T& data,ListNode<T>* prev = nullptr,ListNode<T>* next = nullptr) :
        _data(data),_prev(prev),_next(next)
    {};
    
    ListNode<T>* insertAsPrev(const T& data);
    ListNode<T>* insertAsNext(const T& data);
};

template<typename T>
ListNode<T>* ListNode<T>::insertAsPrev(const T& data)
{
    ListNode<T>* node = new ListNode<T>(data,_prev,this);
    _prev->_next = node;
    _prev = node;

    return node;
}

template<typename T>
ListNode<T>* ListNode<T>::insertAsNext(const T& data)
{
    ListNode<T>* node = new ListNode<T>(data,this,_next);
    _next->_prev = node;
    _next = node;

    return node;
}

#endif
