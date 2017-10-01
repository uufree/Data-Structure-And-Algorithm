/*************************************************************************
	> File Name: vector.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2017年09月28日 星期四 21时12分03秒
 ************************************************************************/

#include"vector.h"
#include<stdlib.h>

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
void Vector<T>::bubbleSort(int low,int hight)
{
    for(int i=low;i<hight;++i)
    {
        for(int j=low+1;j<hight;++j)
        {
            if(_elem[i] > _elem[j])
                std::swap(_elem[i],_elem[j]);
        }
    }
}

template<typename T>
void Vector<T>::selectSort(int low,int hight)
{
    int temp;
    for(int i=low;i<hight;++i)
    {
        for(int j=i;j<hight;++j)
        {
            if(_elem[i] >= _elem[j])
                temp = j;
        }
        std::swap(_elem[i],_elem[temp]);
    }
}

template<typename T>
void Vector<T>::mergeSort(int low,int hight)
{
    if(low < hight)
    {
        int mid = (low + hight) >> 1;
        mergeSort(low,mid);
        mergeSort(mid+1,hight);
        merge(low,mid,hight);
    }
}

template<typename T>
void Vector<T>::merge(int low,int mid,int hight)
{
    int n1 = mid - low + 1;
    int n2 = hight - mid;

    int* array1 = new T[n1];
    int* array2 = new T[n2];

    for(int i=0;i<n1;++i)
        array1[i] = _elem[low+i];

    for(int i=0;i<n2;++i)
        array2[i] = _elem[mid+i+1];
    
    int i=0,j=0;
    for(;low<=mid;++low)
    {
        if(array1[i] <= array2[j])
        {
            _elem[low] = array1[i];
            ++i;
        }
        else
        {
            _elem[low] = array2[j];
            ++j;
        }

        if(i == n1 || j == n2)
            break;
    }

    if(i == n1)
    {
        for(;j < n2;++j)
            _elem[low+1] = array2[j];
    }

    if(j == n2)
    {
        for(;i < n1;++i)
            _elem[low+1] = array1[i];
    }

    delete [] array1;
    delete [] array2;
}

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
    copyFrom(array,0,size);
}

template<typename T>
Vector<T>::Vector(T const* array,int low,int hight)
{
    copyFrom(array,low,hight);
}

template<typename T>
Vector<T>::Vector(Vector<T> const& array)
{
    copyFrom(array._elem,0,array._size);
}

template<typename T>
Vector<T>::Vector(Vector<T> const& array,int low,int hight)
{
    copyFrom(array._elem,low,hight);
}

template<typename T>
Vector<T>::~Vector()
{
    delete [] _elem;
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
int Vector<T>::search(const T& elem,int low,int hight) const
{
    return binSearch(_elem,elem,low,hight);  
}

template<typename T>
int Vector<T>::search(const T& elem) const
{
    return search(elem,0,_size);
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
int Vector<T>::remove(int rank)
{
    for(int i=rank;i<_size;++i)
        _elem[i] = _elem[i+1];
    
    _size -= 1;
    return 1;
}

template<typename T>
int Vector<T>::remove(int low,int hight)
{
    if(low == hight)
        return 0;

    if(low > hight)
        return -1;

    while(hight < _size)
        _elem[low++] = _elem[hight++];

    return  hight - low; 
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
void Vector<T>::insert(const T& elem)
{
    insert(_size,elem);
}

template<typename T>
void Vector<T>::sort(int low,int hight)
{
    switch(rand() % 5)
    {
        case 1:
            bubbleSort(low,hight);
            break;
        case 2:
            selectSort(low,hight);
            break;
        case 3:
            mergeSort(low,hight);
            break;
        case 4:
            heapSort(low,hight);
            break;
        default:
            quickSort(low,hight);
            break;
    }
}

template<typename T>
void Vector<T>::sort()
{
    sort(0,_size);
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
int Vector<T>::deduplicate()
{
    int oldSize = _size;

    int p;
    for(int i=0;i<_size;++i)
        (p=find(_elem[i] < 0)) ? ++i : remove(p);

    return oldSize - _size;
}

template<typename T>
int Vector<T>::uniquify()
{
    int i = 0,j = 0;

    while(++j < _size)
    {
        if(_elem[i] != _elem[j])
            _elem[++i] = _elem[j];
    }
    
    _size = ++i;
    shrink();
    return j - i;
}

template<typename T>
void Vector<T>::traverse(void (*function)(T&))
{
    for(int i=0;i<_size;++i)
        function(_elem[i]);
}

template<typename T>
template<typename VST>
void Vector<T>::traverse(VST& function)
{
    for(int i=0;i<_size;++i)
        function(_elem[i]);
}

