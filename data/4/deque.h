/*************************************************************************
	> File Name: deque.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月18日 星期日 20时43分41秒
 ************************************************************************/

#ifndef _DEQUE_H
#define _DEQUE_H

#include"../2/vector.h"

template<typename T>
class Deque : public Vector<T>
{
    public:
        void push(T& elem){Vector<T>::insert(elem);};
        T pop(){return Vector<T>::remove(0);};
        T& top(){return Vector<T>::operator[](0);};
        T& tail(){return Vector<T>::operator[](Vector<T>::size()-1);};
};

#endif
