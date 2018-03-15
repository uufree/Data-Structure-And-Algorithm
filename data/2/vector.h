/*************************************************************************
	> File Name: vector.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年02月09日 星期五 16时04分01秒
 ************************************************************************/

//除了几个排序算法没有写,其他的测试完毕..
//上面的测试是偷懒了...靠..
//真实情况是：和Vector<T>拷贝相关的都有点问题..

#ifndef _VECTOR_H
#define _VECTOR_H

#include<iostream>
#include<cstdlib>

static const int DEFAULT_CAPACITY = 10;

template<typename T>
class Vector
{
    public:
        explicit Vector(int capacity_ = DEFAULT_CAPACITY,int size_ = 0,T elem_ = 0);
        Vector(T const* array_,int low_,int high_){copyFrom(array_,low_,high_);}
        Vector(T const* array_,int len_){copyFrom(array_,0,len_);}

//这两个复制构造函数有问题...
        Vector(Vector<T> const& array_,int low_,int high_){copyFrom(array_,low_,high_);}
        Vector(Vector<T> const& array_){copyFrom(array_,0,array_.size());}
        
        ~Vector(){delete [] _elem;};
        T& operator[](int index_) const {return _elem[index_];};

//这个函数也待观察        
        Vector<T>& operator=(Vector<T> const& array_){copyFrom(array_,0,array_.size());return *this;}

    protected:
        void copyFrom(T const* array_,int low_,int high_);
        
//这个函数待观察
        void copyFrom(Vector<T> const& array_,int low_,int high_);
        
        void expand();
        void shrink();

        void bubbleSort(int low_,int high_);//冒泡排序
        void selectionSort(int low_,int high_);//选择排序
        void merge(int low_,int mid_,int high_);
        void mergeSort(int low_,int high_);//归并排序
        void quicksort(int low_,int high_);///快速排序
        void heapSort(int low_,int high_);//堆排序
        T max(int low_,int high_);//最大值元素
     
    public:
    //读接口
        int size() const {return _size;}
        bool empty() const {return !_size;}
        int isSort() const;
        int find(T const& elem_) const {return find(elem_,0,_size);};//无序查找
        int find(T const& elem_,int low_,int high_) const;
        int findMax() const{findMax(0,_size);};
        int findMax(int low_,int high_) const;

        int search(T const& elem_) const {return search(elem_,0,_size);};//有序查找
        int search(T const& elem_,int low_,int high_) const;
        
    //写接口    
        T remove(int index_)
        {
            T elem = _elem[index_];
            remove(index_,index_+1);
            return elem;
        }

        int remove(int low_,int high_);
        int insert(T const& elem_){return insert(_size,elem_);};
        int insert(int index_,T const& elem_);

        void sort(int low_,int high_);
        void sort(){sort(0,_size);};
        void unsort(int low_,int high_);
        void unsort(){unsort(0,_size);};
        
        int deduplicate();//无序去重
        int uniquify();//有序去重
        int capacity(){return _capacity;};

    private:
        int _size;;
        int _capacity;
        T* _elem;
};

template<typename T>
Vector<T>::Vector(int capacity_,int size_,T elem_) :
    _capacity(capacity_),
    _elem(new T[_capacity])
{
    for(_size = 0;_size < size_;_size++)
        _elem[_size++] = elem_;
}

template<typename T>
void Vector<T>::copyFrom(T const* array_,int low_,int high_)
{
    if(_elem)
        delete [] _elem;
    _elem = new T[_capacity=((high_-low_)<<1)];
   
    _size = 0;
    while(low_ < high_)
        _elem[low_++] = array_[_size++];
}

template<typename T>
void Vector<T>::copyFrom(Vector<T> const& array_,int low_,int high_)
{
/*    
    if(_elem)
        delete [] _elem;
    _elem = new T[_capacity=((high_-low_) << 1)];
    _size = 0;

    while(low_ < high_)
        _elem[low_++] = array_[_size++];
*/
}

template<typename T>
void Vector<T>::expand()
{
    if(_size < _capacity)//尚未满员,不需要扩容
        return;
    if(_capacity < DEFAULT_CAPACITY)//不能低于最小的容量
        _capacity = DEFAULT_CAPACITY;
    
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1];
    for(int i=0;i<_size;i++)
        _elem[i] = oldElem[i];

    delete [] oldElem;
}

template<typename T>
void Vector<T>::shrink()
{
    if(_capacity < (DEFAULT_CAPACITY<<1))//保证不会缩容到DEFAUTL_CAPACITY以下
        return;
    if((_capacity>>2) < _size)//空闲3/4之上才允许缩容
        return;
    
    T* oldElem = _elem;
    _elem = new T[_capacity=((_capacity>>=1))];
    for(int i=0;i<_size;i++)
        _elem[i] = oldElem[i];

    delete [] oldElem;
}

template<typename T>
int Vector<T>::isSort() const
{
    int n = 0;
    for(int i = 1;i < _size;i++)
        if(_elem[i] > _elem[i-1])
            ++n;
    return n;
}

template<typename T>
T Vector<T>::max(int low_,int high_)
{
    T elem;
    if(isSort())
        _elem[low_] < _elem[high_-1] ? elem=_elem[high_-1] : elem=_elem[low_];
    else
        elem = _elem[findMax(low_,high_)];
    return elem;
}

template<typename T>
int Vector<T>::find(T const& elem_,int low_,int high_) const
{
    while((low_ < high_--) && (_elem[high_] != elem_));
    return high_;
}

template<typename T>
int Vector<T>::findMax(int low_,int high_) const
{
    int index = low_;
    T elem = _elem[low_];
    while(++low_ < high_)
        if(elem < _elem[low_])
            index = low_;
    return index;
}

template<typename T>
int Vector<T>::search(T const& elem_,int low_,int high_) const
{
    if(elem_ > _elem[high_-1] || elem_ < _elem[low_])
        return -1;
    
    int index;
    while((index=((low_ + high_)>>1)))
        if(_elem[index] > elem_)
            high_ = index;
        else if(_elem[index] < elem_)
            low_ = index;
        else
            break;
    
    return index;
}

template<typename T>
int Vector<T>::remove(int low_,int high_)
{
    if(low_ == high_)
        return 0;
    while(high_ < _size)
        _elem[low_++] = _elem[high_++];
    _size = low_;
    shrink();
    return (high_-low_);
}

template<typename T>
int Vector<T>::insert(int index_,T const& elem_)
{
    expand();
    for(int i=_size;i>index_;i--)
        _elem[i] = _elem[i-1];
    _elem[index_] = elem_;
    ++_size;
    return index_;
}

template<typename T>
void Vector<T>::sort(int low_,int high_)
{
    switch(rand() % 5)
    {
        case 1:
            bubbleSort(low_,high_);break;
        case 2:
            selectionSort(low_,high_);break;
        case 3:
            mergeSort(low_,high_);break;
        case 4:
            heapSort(low_,high_);break;
        default:
            quicksort(low_,high_);break;
    }
}

template<typename T>
void Vector<T>::unsort(int low_,int high_)
{
    for(int i=high_-low_;i > 0;i--)
        std::swap(_elem[i-1],_elem[rand() % i]);
}

template<typename T>
int Vector<T>::deduplicate()
{
    int oldSize = _size;
    int index = 1;
    while(index < _size)
        (find(_elem[index],0,index) < 0) ? index++ : remove(index);
    return oldSize - _size;
}

template<typename T>
int Vector<T>::uniquify()
{
    int first = 0,second = 0;
    while(++second < _size)
        if(_elem[first] != _elem[second])
            _elem[++first] = _elem[second];
    _size = ++first;
    shrink();
    return second - first;
}

#endif 
