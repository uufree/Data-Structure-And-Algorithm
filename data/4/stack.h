/*************************************************************************
	> File Name: stack.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月14日 星期三 21时24分27秒
 ************************************************************************/

//我应该学一学异常捕捉机制...

#ifndef _STACK_H
#define _STACK_H

#include"../2/vector.h"

template<typename T>
class Stack : public Vector<T>
{
    public:
        void push(T& elem_){Vector<T>::insert(elem_);};
        T pop(){return Vector<T>::remove(Vector<T>::size()-1);};
        T& top(){return Vector<T>::operator[](Vector<T>::size()-1);};
};

#endif
