/*************************************************************************
	> File Name: List.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年10月03日 星期二 20时15分36秒
 ************************************************************************/

#ifndef _LIST_H
#define _LIST_H

//设计合适的哨兵节点用以简化算法描述

#include"ListNode.h"

template<typename T>
class List
{
    protected:
        void init();
        void clear();
        void copyNodes(const ListNode<T>* pos,int size);
        void merge(ListNode<T>* pos,int size,ListNode<T>* pos2,int size2);
        void mergeSort(ListNode<T>* pos,int size);
        void selectSort(ListNode<T>* pos,int size);
        void insertSort(ListNode<T>* pos,int size);
        
    public:
        List();
        List(List<T> const& list);
        List(List<T> const& list,int pos,int size);
        List(const ListNode<T>* p,int n);
        ~List();

    //只读接口
        inline int size() const;
        inline bool empty() const;
        const T& operator[](int pos) const;
        T& operator[](int pos);
        inline ListNode<T>* first() const;
        inline ListNode<T>* last() const;
        inline bool vaild(ListNode<T>* pos) const;   //查询位置是否合法
        ListNode<T>* find(const ListNode<T>* pos,int steps,T const& data) const;
        ListNode<T>* find(T const& data) const;     //无序查找data的位置
        ListNode<T>* search(T const& data) const;   //有序查找data的位置
        ListNode<T>* search(ListNode<T>* pos,int steps,T const& data) const;
        ListNode<T>* max(ListNode<T>* pos1,int size) const;
        ListNode<T>* min(ListNode<T>* pos1,int size) const;
        ListNode<T>* max() const;
        ListNode<T>* min() const;
    
    //可写接口
        ListNode<T>* insertAsFirst(T const& data);
        ListNode<T>* insertAsLast(T const& data);
        ListNode<T>* insertPrev(ListNode<T>* pos,T const& data);
        ListNode<T>* insertNext(ListNode<T>* pos,T const& data);
        T remove(ListNode<T>* pos);
        void sort(ListNode<T>* pos,int size);
        void sort();
        int deduplicate();  //无序去重
        int uniquility();   //有序去重
        void reverse();     //反转顺序
        void traverse(void (*)(T& data));
        template<typename VST> void traverse(VST& vst); 
    
    private:
        int _size;
        ListNode<T>* _head;
        ListNode<T>* _tail;

};  

#endif
