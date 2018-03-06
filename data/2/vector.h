/*************************************************************************
	> File Name: vector.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月09日 星期五 16时04分01秒
 ************************************************************************/

#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>
#include<cstdlib>

static const int DEFAULT_CAPACITY = 10;

template<typename T>
class Vector
{
    public:
        explicit Vector(int capacity_ = DEFAULT_CAPACITY,int size_ = 0,T elem_ = 0){_elem = new T[capacity_];for(_size=0;_size<size_;_size++){_elem[_size] = elem_;};}
        Vector(T const* array_,int low_,int high_){copyFrom(array_,low_,high_);}
        Vector(T const* array_,int len_){copyFrom(array_,0,len_);}
        Vector(Vector<T> const& array_,int low_,int high_){copyFrom(array_,low_,high_);}
        Vector(Vector<T> const& array_){copyFrom(array_,0,array_.size());}
        ~Vector(){delete [] _elem;};
        
        T& operator[](int index_) const{index_ < _size ? _elem[index_]:-1;};
        Vector<T>& operator=(Vector<T> const& array_){copyFrom(array_,0,array_.size());return *this;}

    protected:
        void copyFrom(T const* array_,int low_,int high_)
        {
            if(_elem)
                delete [] _elem;
            _elem = new T[_capacity = ((high_-low_) << 1)];
            _size = 0;

            while(low_ < high_)
                _elem[low_++] = array_[_size++];
        }

        void copyFrom(Vector<T> const& array_,int low_,int high_)
        {
            if(_elem)
                delete [] _elem;
            _elem = new T[_capacity=((high_-low_)<<1)];
            _size = 0;

            while(low_ < high_)
                _elem[low_++] = array_[_size++];
        }
        
        void expand()
        {
            if(_size < _capacity) 
                return;
            if(_capacity < DEFAULT_CAPACITY) 
                _capacity = DEFAULT_CAPACITY;
            
            T* oldElem = _elem;
            _elem = new T[_capacity <<= 1];
            for(int i=0;i<_size;i++)
               _elem[i] = oldElem[i];

            delete [] oldElem;
        }
        
        void shrink()
        {
            if(_capacity < (DEFAULT_CAPACITY<<1))
                return;
            if((_capacity>>2) > _size)
                return;

            T* oldElem = _elem;
            _elem = new T[_capacity>>=1];
            for(int i=0;i<_size;i++)
                _elem[i] = oldElem[i];
            
            delete [] oldElem;
        }

        void bubbleSort(int low_,int high_);//冒泡排序
        void selectionSort(int low_,int high_);//选择排序
        void merge(int low_,int mid_,int high_);
        void mergeSort(int low_,int high_);//归并排序
        void quicksort(int low_,int high_);///快速排序
        void heapSort(int low_,int high_);//堆排序
        int max(int low_,int high_);//最大值元素
    
    public:
    //读接口
        int size() const {return _size;}
        bool empty() const {return !_size;}
        int isSort() const;
        int find(T const& elem_) const {return find(elem_,0,_size);};//无序查找
        int find(T const& elem_,int low_,int high_) const
        {
            while((low_ < high_--) && (elem_ != _elem[high_]));
            return high_;
        }
        int search(T const& elem_) const {return search(elem_,0,_size);};//有序查找
        int search(T const& elem_,int low_,int high_) const
        {

        }
        
    //写接口    
        T remove(int index_)
        {
            T elem = _elem[index_];
            remove(index_,index_+1);
            return elem;
        }

        int remove(int low_,int high_)
        {
            if(low_ == high_)
                return 0;
            while(high_ < _size)
                _elem[low_++] = _elem[high_++];
            _size = low_;
            shrink();
            return (high_-low_);
        }

        int insert(T const& elem_){return insert(_size,elem_);};
        int insert(int index_,T const& elem_)
        {
            expand();
            for(int i=_size;i>index_;i--)
                _elem[i] = _elem[i-1];
            _elem[index_] = elem_;
            ++_size;
        }

        void sort(int low_,int high_);
        void sort(){sort(0,_size);};
        void unsort(int low_,int high_)
        {
            for(int i=high_-low_;i>0;i--)
                std::swap(_elem[i-1],_elem[rand()%i]);
        }

        void unsort(){unsort(0,_size);};
        int deduplicate();//无序去重
        int uniquify();//有序去重

    private:
        int _size;;
        int _capacity;
        T* _elem;
};


#endif 
