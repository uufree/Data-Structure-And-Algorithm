/*************************************************************************
	> File Name: list.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月08日 星期四 16时53分43秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H

#define NULL (void*)0

template <typename T>
struct ListNode
{
    T _data;
    ListNode<T>* _prev;
    ListNode<T>* _next;
    
    ListNode(){};
    ListNode(T data_,ListNode<T>* prev_=NULL,ListNode<T>* next_=NULL) :
        _data(data_),
        _prev(prev_),
        _next(next_)
    {};
     
    ListNode<T>* insertAsPrev(T const& data_);
    ListNode<T>* insertAsNext(T const& data_);
};

template<typename T>
ListNode<T>* ListNode<T>::insertAsPrev(T const& data_)
{
    ListNode<T>* node = new ListNode<T>(data_,_prev,this);
    _prev->_next = node;
    _prev = node;
    return node;
}

template<typename T>
ListNode<T>* ListNode<T>::insertAsNext(T const& data_)
{
    ListNode<T>* node = new ListNode<T>(data_,this,_next);
    _next->_prev = node;
    _next = node;
    return node;
}

template<typename T>
class List
{
    public:
        explicit List(){init();};
        List(List<T> const& list_){copyNotes(list_.first(),list_.size());};
        List(List<T> const& list_,int rank_,int size_){copyNotes(list_[rank_],size_);};
        List(ListNode<T> const& nodes_,int size_){copyNotes(nodes_,size_);};
        ~List(){clear();delete _header;delete _tailer;};

    //read interface
        int size() const{return _size;};
        bool empty() const{return _size == 0;};
        T const& operator=(int rank_) const;
        ListNode<T>* first() const {return _header->_next;};
        ListNode<T>* last() const {return _tailer->_prev;};
        bool isSort() const;
        ListNode<T>* find(T& data_) const{return find(_header,_size,data_);};
        ListNode<T>* find(ListNode<T>* nodes_,int size_,T& data_) const; 
        ListNode<T>* search(T& data_) const{return search(_header,_size,data_);};
        ListNode<T>* search(ListNode<T>* nodes_,int size_,T& data_) const;
        ListNode<T>* max(ListNode<T>* nodes_,int size_) const;
        ListNode<T>* max() const{return max(_header,_size);};
        ListNode<T>* min(ListNode<T>* nodes_,int size_) const;
        ListNode<T>* min() const{return min(_header,_size);};
    
    //write interface
        ListNode<T>* insertAsFirst(T& data_);
        ListNode<T>* insertAsLast(T& data_);
        ListNode<T>* insertAsPrev(ListNode<T>* nodes_,T& data_);
        ListNode<T>* insertAsNext(ListNode<T>* nodes_,T& data_);
        T remove(ListNode<T>* nodes_);
        void sort(ListNode<T>* nodes_,int size_);
        void sort(){sort(_header,_size);};
        int deduplicate();//无序去重
        int uniquify();//有序去重

    protected:
        void init();
        int clear();
        void copyNotes(ListNode<T>* nodes_,int size_);
        void merge(ListNode<T>* first_,int size1_,List<T>& list_,ListNode<T>* second_,int size2_);
        void mergeSort(ListNode<T>* nodes_,int size_);
        void selectionSort(ListNode<T>* nodes_,int size_);
        void insertSort(ListNode<T>* nodes_,int size_);
    
    private:
        int _size;
        ListNode<T>* _header;
        ListNode<T>* _tailer;
};


#endif
