/*************************************************************************
	> File Name: list.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月08日 星期四 16时53分48秒
 ************************************************************************/

#include<cstdlib>
#include"list.h"

template<typename T>
void List<T>::init()
{
    _header = new ListNode<T>;
    _tailer = new ListNode<T>;
    _header->_next = _tailer;_header->_prev = NULL;
    _tailer->_prev = _header;_tailer->_next = NULL;
    _size = 0;
}

template<typename T>
T const& List<T>::operator=(int rank_) const
{
    ListNode<T>* node = first();
    if(rank_ < _size)
        while(rank_--)
            node = node->_next;
    return node->_data;
}

template<typename T>
ListNode<T>* List<T>::find(ListNode<T>* nodes_,int size_,T& data_) const
{
    while(size_--)
        if(data_ == (nodes_->_next)->_data)
           return nodes_; 
}

template<typename T>
ListNode<T>* List<T>::insertAsFirst(T& data_)
{
    _size++;
    return _header->insertAsNext(data_);
}

template<typename T>
ListNode<T>* List<T>::insertAsLast(T& data_)
{
    _size++;
    return _tailer->insertAsPrev(data_);
}

template<typename T>
ListNode<T>* List<T>::insertAsPrev(ListNode<T>* nodes_,T& data_)
{
    _size++;
    return nodes_->insertAsPrev(data_);
}

template<typename T>
ListNode<T>* List<T>::insertAsNext(ListNode<T>* nodes_,T& data_)
{
    _size++;
    return nodes_->insertAsNext(data_); 
}

template<typename T>
void List<T>::copyNotes(ListNode<T>* nodes_,int size_)
{
    init();
    while(size_--)
    {
        insertAsLast(nodes_->_data);
        nodes_=nodes_->next;
    }
}

template<typename T>
T List<T>::remove(ListNode<T>* nodes_)
{
    T data = nodes_->_data;
    nodes_->_prev->_next = nodes_->_next;
    nodes_->_next->_prev = nodes_->_prev;
    delete nodes_;
    return data;
}

template<typename T>
int List<T>::clear()
{
    int oldSize = _size;
    while(_size--)
        remove(_header->_next);
    return oldSize - _size;
}

template<typename T>
int List<T>::deduplicate()
{
    if(_size < 2)
        return 0;
    ListNode<T>* node = _header;
    int oldSize = _size,rank = 0;
    while((node=node->_next) != _tailer)
    {
        ListNode<T>* dnode = find(node,rank,node->_data);
        dnode ? remove(dnode) : rank++;
    }
    return oldSize - _size;
}

template<typename T>
int List<T>::uniquify()
{
    if(_size < 2)
        return 0;
    int oldSize = _size;
    ListNode<T>* first = first();
    ListNode<T>* second;
    while((second=first->_next) != _tailer)
        if(first->_data != second->_data)
            first = second;
        else
            remove(second);
    return oldSize - _size;
}

//在节点nodes_的size_前驱中找到不大于data_的节点
template<typename T>
ListNode<T>* List<T>::search(ListNode<T>* nodes_,int size_,T& data_) const
{
    while(size_--)
        if(nodes_->_data <= data_)
            break;
    return nodes_;
}

template<typename T>
void List<T>::sort(ListNode<T>* nodes_,int size_)
{
    switch(rand() % 3)
    {
        case 1:
            insertSort(nodes_,size_);break;
        case 2:
            selectionSort(nodes_,size_);break;
        default:
            mergeSort(nodes_,size_);break;
    }
}

template<typename T>
ListNode<T>* List<T>::max(ListNode<T>* nodes_,int size_) const
{
    ListNode<T>* node = nodes_;
    while(size_--)
        node->_data > nodes_->_data ? node = nodes_,nodes_=nodes_->_next : nodes_=nodes_->_next;
    return node;
}

template<typename T>
ListNode<T>* List<T>::min(ListNode<T>* nodes_,int size_) const
{
    ListNode<T>* node = nodes_;
    while(size_--)
        node->_data < nodes_->_data ? node = nodes_,nodes_=nodes_->_next : nodes_=nodes_->_next;
    return node;
}

template<typename T>
void List<T>::insertSort(ListNode<T>* nodes_,int size_)
{
    for(int i=0;i<size_;i++)
    {
        insertAsNext(search(nodes_,i,nodes_->_data),nodes_->_data);
        nodes_ = nodes_->_next;
        remove(nodes_->_prev);
    }
}

template<typename T>
void List<T>::selectionSort(ListNode<T>* nodes_,int size_)
{
    ListNode<T>* head = nodes_->_prev;
    ListNode<T>* tail = nodes_;
    for(int i=0;i<size_;i++)
        tail = tail->_next;

    while(size_--)
    {
        ListNode<T>* node = max(head->_next,size_);
        insertAsPrev(tail,remove(node));
        tail = tail->_prev;
    }
}








