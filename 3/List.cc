/*************************************************************************
	> File Name: List.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 21时13分42秒
 ************************************************************************/

#include"List.h"

template<typename T>
void List<T>::init()
{
    _head = new ListNode<T>;
    _tail = new ListNode<T>;
    
    _head->next = _tail;
    _head->prev = nullptr;
    _tail->prev = _head;
    _tail->next = nullptr;
    _size = 0;
}

template<typename T>
void List<T>::clear()
{
    
}

template<typename T>
inline ListNode<T>* List<T>::first() const
{
    return _head->next; 
}

template<typename T>
inline ListNode<T>* List<T>::last() const
{
    return _tail->prev;
}

template<typename T>
T& List<T>::operator[](int pos)
{
    ListNode<T>* node = first();
    while(--pos > 0)
        node = node->next;

    return node->_data;
}

template<typename T>
const T& List<T>::operator[](int pos) const
{
    ListNode<T>* node = first();
    while(pos-- > 0)
        node = node->next;

    return node->_data;
}

template<typename T>
ListNode<T>* List<T>::find(const ListNode<T>* pos,int steps,T const& data) const
{
    while(steps-- > 0)
    {
        if((pos = (pos->next)->_data) == data)
            return pos;
    }

    return nullptr;
}

template<typename T>
ListNode<T>* List<T>::find(T const& data) const
{
    find(_head,_size,data);
}

template<typename T>
ListNode<T>* List<T>::insertAsHead(T const& data)
{
    _size++;
    return _head->insertAsNext(data); 
}

template<typename T>
ListNode<T>* List<T>::insertAsTail(T const& data)
{
    _size++;
    return _tail->insertAsPrev(data);
}

template<typename T>
ListNode<T>* List<T>::insertPrev(ListNode<T>* pos,T const& data)
{
    ++_size;
    pos->insertAsPrev(data);
}

template<typename T>
ListNode<T>* List<T>::insertNext(ListNode<T>* pos,T const& data)
{
    ++_size;
    pos->insertAsNext(data);
}









