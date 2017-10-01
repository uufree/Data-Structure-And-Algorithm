/*************************************************************************
	> File Name: vector.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月28日 星期四 21时11分57秒
 ************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include<stdlib.h>
#include<iostream>

#define DEFAULT_SIZE 10

template<typename T>
class Vector
{
    protected:
        int _size;  //规模
        int _capacity;   //容量
        T* _elem;    //数据区

        void copyFrom(T const* array,int low,int hight);
        void expand(); 
        void shrink();
        void bubbleSort(int low,int hight);     //冒泡排序
        void selectSort(int low,int hight);     //选择排序
        void mergeSort(int low,int hight);      //归并排序
        void merge(int low,int mid,int hight);      
//未实现        
        int partition(int low,int hight);       //轴点构造算法
        void quickSort(int low,int hight);      //快速排序
        void heapSort(int low,int hight);       //堆排序
    
    public:
        Vector(int capacity = DEFAULT_SIZE,T elem = 0);
        Vector(T const* array,int size);
        Vector(T const* array,int low,int hight);
        Vector(Vector<T> const& array);
        Vector(Vector<T> const& array,int low,int hight);
        ~Vector();

//只读接口
        int size() const {return _size;};
        bool empty() const {return _size == 0;};
        int find(const T& elem) const;
        int find(const T& elem,int low,int hight) const;
        int search(const T& elem) const;
        int search(const T& elem,int low,int right) const;

//可写接口
        T& operator[](int rank) const;
        Vector<T>& operator=(const Vector<T>& elem);
        int remove(int rank);
        int remove(int low,int hight);
        void insert(int rank,const T& elem);
        void insert(const T& elem);
        void sort(int low,int hight);
        void sort();
        void unsort();
        void unsort(int low,int hight);
        int deduplicate(); //无序去重
        int uniquify();    //有序去重

        void traverse(void (*)(T&));
        template<typename VST> void traverse(VST&); //函数对象
};

template<typename T>
void permute(Vector<T>& vec)
{
    for(int i=vec.size();i>0;--i)
        std::swap(vec[i-1],vec[rand()%i]);
}

template<typename T>
int binSearch(const T* array,const T& elem,int low,int hight)
{
    while(low < hight)
    {
        int mid = (low + hight) >> 1;
        (elem < array[mid]) ? hight = mid : low = mid;
    }
    return (elem == array[low]) ? low : -1;
}

#endif
