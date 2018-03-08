/*************************************************************************
	> File Name: list.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月08日 星期四 16时53分48秒
 ************************************************************************/

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
void List<T>::clear()
{

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





