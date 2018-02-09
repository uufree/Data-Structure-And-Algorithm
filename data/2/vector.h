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
        explicit Vector(int capacity_ = DEFAULT_CAPACITY,int size_ = 0,T elem_ = 0){_elem = new T[capacity_];for(_size=0;_size<size_;_size++){_elem[_size] = elem_;};std::cout << "_size: " << _size << std::endl;}
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
            std::cout << "_size: " << _size << std::endl;    
        }

        void copyFrom(Vector<T> const& array_,int low_,int high_)
        {
            if(_elem)
                delete [] _elem;
            _elem = new T[_capacity=((high_-low_)<<1)];
            _size = 0;

            while(low_ < high_)
                _elem[low_++] = array_[_size++];
            std::cout << "_size: " << _size << std::endl;    
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
            if(_capacity < DEFAULT_CAPACITY)
                return;
            if(_capacity>>2 < _size)
                return;

            T* oldElem = _elem;
            _elem = new T[_capacity>>=1];
            for(int i=0;i<_size;i++)
                _elem[i] = oldElem[i];
            
            delete [] oldElem;
        }

        void bubbleSort(int low_,int high_);
        void selectionSort(int low_,int high_);
        void merge(int low_,int mid_,int high_);
        void mergeSort(int low_,int high_);
        void quicksort(int low_,int high_);
        void heapSort(int low_,int high_);
        int maxIndex(int low_,int high_);
    
    public:
        int size() const {return _size;}
        bool empty() const {return !_size;}
        int isSort() const;
        int find(T const& elem_) const {return find(elem_,0,_size);};
        int find(T const& elem_,int low_,int high_) const;
        int search(T const& elem_) const {return search(elem_,0,_size);};
        int search(T const& elem_,int low_,int high_) const;
        
        T remove(int index_);
        int remove(int low_,int high_);
        int insert(T const& elem_){return insert(_size,elem_);};
        int insert(int index_,T const& elem_);
        void sort(int low,int high);
        void sort(){sort(0,_size);};
        void unsort(int low,int high)
        {
            
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
