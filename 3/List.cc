/*************************************************************************
	> File Name: List.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 21时13分42秒
 ************************************************************************/

#include<stdlib.h>
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
    while(_size--)
    {
        remove(_head->next);    
    }
}

template<typename T>
void List<T>::copyNodes(const ListNode<T>* pos,int size)
{
    init();
    while(size--)
    {
        insertAsLast(pos->data);
        pos = pos->_next;
    }
}

template<typename T>
void List<T>::merge(ListNode<T>* pos,int size,ListNode<T>* pos2,int size2)
{
    ListNode<T>* ppos = pos;
    while(size2 > 0)
    {
        if(pos->_data < pos2->_data && size > 0)
        {
            pos = pos->_next;
            ppos = pos;
            --size;
        }
        else
        {
            insertPrev(ppos,pos2->_data);
            pos2 = pos2->_next;
            --size2;
        }
    }
}

template<typename T>
void List<T>::mergeSort(ListNode<T>* pos,int size)
{
    if(size < 2)
        return;
    int mid = size >> 1;
    ListNode<T>* ppos = pos;
    
    for(int i=0;i<mid;++i)
        ppos = ppos->next;
    
    mergeSort(pos,mid);
    mergeSort(ppos,size-mid);
    merge(pos,mid,ppos,size-mid);
}

template<typename T>
void List<T>::selectSort(ListNode<T>* pos,int size)
{
    ListNode<T>* head_ = pos->_prev;
    ListNode<T>* tail_ = pos;

    for(int i=0;i<size;++i)
        tail_ = tail_->next;

    while(size > 1)
    {   
        ListNode<T>* max_ = max(first(),size);
        insertPrev(tail_,max_->_data);
        tail_ = tail_->_prev;
        --size;
    }
}

template<typename T>
void List<T>::insertSort(ListNode<T>* pos,int size)
{
    for(int i=0;i<size;++i)
    {
        insertAsNext(search(pos->_data,i,pos->_data),pos->data);
        pos = pos->_next;
        remove(pos->_prev);
    }
}

template<typename T>
List<T>::List()
{
    init();
}

template<typename T>
List<T>::List(List<T> const& list)
{
    copyNodes(list.first(),list.size());
}

template<typename T>
List<T>::List(List<T> const& list,int pos,int size)
{
    copyNodes(list[pos],size);
}

template<typename T>
List<T>::List(const ListNode<T>* pos,int size)
{
    copyNodes(pos,size);
}

template<typename T>
List<T>::~List()
{
    clear();
    delete _head;
    delete _tail;
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
ListNode<T>* List<T>::search(ListNode<T>* pos,int steps,T const& data) const
{
    while(steps--)
    {
        if((pos=pos->_next)->_data == data)
            return pos;
    }
    
    return nullptr;
}

template<typename T>
ListNode<T>* List<T>::search(T const& data) const
{
    ListNode<T>* pos = _head;
    return search(pos,_size,data);
}

template<typename T>
ListNode<T>* List<T>::max(ListNode<T>* pos,int size) const
{
    ListNode<T>* pos_ = pos;
    while(size--)
    {
        if((pos=pos->_next)->_data > pos_->_data)
            pos_ = pos;
    }
    return pos_;
}

template<typename T>
ListNode<T>* List<T>::min(ListNode<T>* pos,int size) const
{
    ListNode<T>* pos_ = pos;
    while(size--)
    {
        if((pos=pos->_next)->_data < pos_->_data)
            pos_ = pos;
    }
    return pos_;
}

template<typename T>
ListNode<T>* List<T>::max() const
{
    return max(_head,_size);
}

template<typename T>
ListNode<T>* List<T>::min() const
{
    return min(_head,_size);
}

template<typename T>
ListNode<T>* List<T>::insertAsFirst(T const& data)
{
    _size++;
    return _head->insertAsNext(data); 
}

template<typename T>
ListNode<T>* List<T>::insertAsLast(T const& data)
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

template<typename T>
T List<T>::remove(ListNode<T>* pos)
{
    T data = pos->_data;
    pos->_prev->_next = pos->_next;
    pos->_next->prev = pos->_prev;
    delete pos;
    --_size;
    return data;
}

template<typename T>
void List<T>::sort(ListNode<T>* pos,int size)
{
    switch(rand() % 3)
    {
        case 1:
            insertSort(pos,size);
            break;
        case 2:
            selectSort(pos,size);
            break;
        default:
            mergeSort(pos,size);
    }
}

template<typename T>
void List<T>::sort()
{
    sort(_head,_size);
}
    
template<typename T>
int List<T>::deduplicate()
{
    if(_size < 2)
        return 0;
    
    int oldSize = _size;
    ListNode<T>* node = _head->_next;

    while(node != _tail)
    {
        ListNode<T>* node_ = find(node,oldSize,node->_data);
        node_ ? remove(node_) : node=node->_next;
        
    }

    return oldSize - _size;
}

template<typename T>
void List<T>::traverse(void (*function)(T& data))
{
    for(ListNode<T>* node = _head->_next;node != _tail;++node)
        function(node->_data);
}

template<typename T>
template<typename VST>
void List<T>::traverse(VST& vst)
{
    for(ListNode<T>* node=_head->_next;node!=_tail;++node)
        vst(node->_data);
}

template<typename T>
int List<T>::uniquility()
{
    if(_size < 2)   
        return 0;
    
    int oldSize = _size;
    ListNode<T>* node = _head->_next;
    while(node != _tail)
        node->_data == node->_next->_data ? remove(node->next) : node=node->_next;    
    
    return oldSize - _size;
}


























