/*************************************************************************
	> File Name: skiplist.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月23日 星期五 21时37分16秒
 ************************************************************************/

#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#include"../3/list.h"
#include"../7/binarySearchTree.h"

template<typename T>
struct QuadListNode
{
    T _entry;
    QuadListNode<T>* _pred;
    QuadListNode<T>* _succ;
    QuadListNode<T>* _above;
    QuadListNode<T>* _below;
    
    QuadListNode(T entry = T(),QuadListNode<T>* pred = NULL,QuadListNode<T>* succ = NULL,QuadListNode<T>* above = NULL,QuadListNode<T>* below = NULL) :
        _entry(entry),
        _pred(pred),
        _succ(succ),
        _above(above),
        _below(below)
    {};

    QuadListNode<T>* insertAsSuccAbove(T const& elem,QuadListNode<T>* node);//以当前的节点为前驱,node为下临
};

template<typename T>
class QuadList
{
    public:
        QuadList(){init();};
        ~QuadList(){clear();delete _header;delete _tailer;};
        int size() const {return _size;};
        bool empty() const {return !_size;};
        QuadListNode<T>* first() const {return _header->_succ;};
        QuadListNode<T>* last() const {return _tailer->_pred;};
        bool vaild(QuadListNode<T>* node) const {return node & (node!=_header) & (node!=_tailer);};

        T remove(QuadListNode<T>* node);
        QuadListNode<T>* insertAsSuccAbove(T const& elem,QuadListNode<T>* s_node,QuadListNode<T>* a_node);
        void traverse(void (*)(T&));
        template<typename VST> void traverse(VST&);

    private:
        int _size;
        QuadListNode<T>* _header;
        QuadListNode<T>* _tailer;

    protected:
        void init();
        void clear();
};


template<typename K,typename V>
struct Directory
{
    virtual int size() const = 0;
    virtual bool put(K,V) = 0;
    virtual V* get(K) = 0;
    virtual bool remove(K) = 0;
};

template<typename K,typename V>
class SkipList : public Directory<K,V>,public List<QuadList<Entry<K,V>>*>
{
    protected:
        bool skipSearch(ListNode<QuadList<Entry<K,V>>*>*& qlist,QuadListNode<Entry<K,V>>*& p,K& k);
    
    public:
        int size() const override {return List<QuadList<Entry<K,V>>*>::empty() ? 0 : List<QuadList<Entry<K,V>>*>::last()->_data->size();};
        int level() const {return List<QuadList<Entry<K,V>>*>::size();};    
        bool put(K key,V value) override;
        V* get(K key) override;
        bool remove(K key) override;
};

#endif
