/*************************************************************************
	> File Name: binarySearchTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月19日 星期一 17时37分06秒
 ************************************************************************/

#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

#include"../5/binaryTree.h"

template<typename K,typename V>
struct Entry
{
    K _key;V _value;
    Entry(K key = K(),V value = V()) : _key(key),_value(value){};
    Entry(Entry<K,V> const& entry) : _key(entry._key),_value(entry._value){};
    bool operator<(Entry<K,V> const& entry) const{return _key < entry._key;};
    bool operator>(Entry<K,V> const& entry) const{return _key > entry._key;};
    bool operator==(Entry<K,V> const& entry) const{return _key == entry._key;};
    bool operator!=(Entry<K,V> const& entry) const{return _key != entry._key;};
};

template<typename T>
class BinarySearchTree : public BinaryTree<T>
{
    protected:



    public:
        virtual BinaryNode<T>*& search(T const& elem);
        virtual BinaryNode<T>* insert(T const& elem);
        virtual bool remove(T const& elem);
};


#endif
