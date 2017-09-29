/*************************************************************************
	> File Name: vector.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月28日 星期四 21时12分03秒
 ************************************************************************/

#include"vector.h"
#include<stdlib.h>

template<typename T>
Vector<T>::Vector(int capacity,T elem)
{
    _size = 0;
    _capacity = capacity;
    
    for(int i=0;i<capacity;++i)
        _elem[i] = elem;
}

template<typename T>
Vector<T>::Vector(T const* array,int size)
{
     
}

template<typename T>
void Vector<T>::copyFrom(T const* array,int low,int hight)
{
    _elem = new T[_capacity = 2*(hight-low)];
    _size = 0;

    while(low != hight)
        _elem[++_size] = array[++_size];
}

template<typename T>
void Vector<T>::expand()
{
    if(_size < _capacity)
        return;
    
    if(_capacity < DEFAULT_SIZE)
        _capacity = DEFAULT_SIZE;

    T* newElem = new T[_capacity<<=1];
    for(int i=0;i<_size;++i)
        newElem[i] = _elem[i];

    delete [] _elem;
    _elem = newElem;
}

template<typename T>
void Vector<T>::shrink()
{
    if(_capacity < (DEFAULT_SIZE << 1))
        return;

    if((_size << 2) > _capacity)
        return;

    T* newElem = new T[_capacity>>=1];

    for(int i=0;i<_size;++i)
        newElem[i] = _elem[i];

    delete [] _elem;
    _elem = newElem;
}













template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& elem)
{
    if(_elem)
        delete [] _elem;
    
    copyFrom(elem._elem,0,elem.size());
    return *this;
}

template<typename T>
T& Vector<T>::operator[](int rank) const
{
    return _elem[rank];
}

template<typename T>
void Vector<T>::unsort(int low,int hight)
{
    for(int i = hight-1;i > low;--i)
        std::swap(_elem[i],_elem[rand() %i ]);
}

template<typename T>
void Vector<T>::unsort()
{
    unsort(0,_size);
}

template<typename T>
int Vector<T>::find(const T& elem,int low,int hight) const
{
    for(int i = hight-1;i >= low;--i)
    {
        if(_elem[i] == elem)
            return i;
    }

    return -1;
}

template<typename T>
int Vector<T>::find(const T& elem) const
{
    return find(elem,0,_size);
}

template<typename T>
void Vector<T>::insert(int rank,const T& elem)
{
    expand();

    for(int i = _size;i > rank;--i)
        _elem[i] = elem[i-1];

    _elem[rank] = elem;
}

template<typename T>
int Vector<T>::remove(int rank)
{
     
}
