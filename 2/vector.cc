/*************************************************************************
	> File Name: vector.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月28日 星期四 21时12分03秒
 ************************************************************************/

#include"vector.h"

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




template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& elem)
{
    if(_elem)
        delete [] _elem;
    
    copyFrom(elem._elem,0,elem.size());
    return *this;
}




