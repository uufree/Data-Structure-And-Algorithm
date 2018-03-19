/*************************************************************************
	> File Name: binaryTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时03分39秒
 ************************************************************************/

#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include<iostream>
#include"../4/stack.h"
#include"../4/deque.h"
#include<cstdlib>

typedef enum{RB_RED,RB_BLACK} RBColor;

template<typename T>
struct BinaryNode
{
    T _data;
    BinaryNode<T>* _parent;
    BinaryNode<T>* _leftChild;
    BinaryNode<T>* _rightChild;
    int _hight;
    RBColor _color;

    BinaryNode() : 
        _data(T()),
        _parent(NULL),
        _leftChild(NULL),
        _rightChild(NULL),
        _hight(0),
        _color(RB_RED)
    {};

    BinaryNode(T data,BinaryNode<T>* parent = NULL,BinaryNode<T>* leftChild = NULL,BinaryNode<T>* rightChild = NULL,int hight = 0,RBColor color = RB_RED) :
        _data(data),
        _parent(parent),
        _leftChild(leftChild),
        _rightChild(rightChild),
        _hight(hight),
        _color(color)
    {};

    BinaryNode<T>* insertAsLeftChild(T const& data){return _leftChild = new BinaryNode(data,this);}
    BinaryNode<T>* insertAsRightChild(T const& data){return _rightChild = new BinaryNode(data,this);}
    BinaryNode<T>* succ();//取当前节点的直接后继
    void travLevel();
    void travPre();
    void travIn();
    void travPost();

    bool operator==(BinaryNode const& node){return node._data == _data;};
    bool operator<(BinaryNode const& node){return _data < node._data;};
};

template<typename T>
BinaryNode<T>* BinaryNode<T>::succ()
{
    BinaryNode<T>* node = this;
    if(_rightChild)
    {
        node = _rightChild;
        while(HasLeftChild(node))
            node = node->_leftChild;
    }
    else
    {
        while(IsRightChild(node))
            node = node->_parent;
        node = node->_parent;
    }
    return node;
}

template<typename T>
static void travIn_R(BinaryNode<T>* node)
{
    if(node)
    {
        travIn_R(node->_leftChild);
        std::cout << node->_data << std::endl;
        travIn_R(node->_rightChild);
    }
}

template<typename T>
static void travPost_R(BinaryNode<T>* node)
{
    if(node)
    {
        travPost_R(node->_leftChild);
        travPost_R(node->_rightChild);
        std::cout << node->_data << std::endl;
    }
}

template<typename T>
static void travPre_R(BinaryNode<T>* node)
{
    if(node)
    {
        std::cout << node->_data << std::endl;
        travPre_R(node->_leftChild);
        travPre_R(node->_rightChild);
    }
}

template<typename T>
static void travPre_I(BinaryNode<T>* node)
{
    Stack<BinaryNode<T>*> BinaryNodeStack;
    
    while(1)
    {
        while(node)
        {
            std::cout << node->_data << std::endl;
            if(node->_rightChild)
                BinaryNodeStack.push(node->_rightChild);
            node = node->_leftChild;
        }

        if(BinaryNodeStack.empty())
            break;
        node = BinaryNodeStack.pop();
    }
}

template<typename T>
static void travIn_I(BinaryNode<T>* node)
{
    Stack<BinaryNode<T>*> BinaryNodeStack;
    while(1)
    {
        while(node)
        {
            BinaryNodeStack.push(node);
            node = node->_leftChild;
        }
        
        if(BinaryNodeStack.empty())
            break;
        node = BinaryNodeStack.pop();
        std::cout << node->_data << std::endl;
        node = node->_rightChild;
    }
}

template<typename T>
static void travLevel_I(BinaryNode<T>* node)
{
    Deque<BinaryNode<T>*> BinaryNodeDeque;
    BinaryNodeDeque.push(node);
    while(!BinaryNodeDeque.empty())
    {
        node = BinaryNodeDeque.pop();
        std::cout << node->_data << std::endl;
            
        if(HasLeftChild(node))
            BinaryNodeDeque.push(node->_leftChild);
        if(HasRightChild(node))
            BinaryNodeDeque.push(node->_rightChild);
    }
}

template<typename T>
void BinaryNode<T>::travLevel()
{travLevel_I(this);}

template<typename T>
void BinaryNode<T>::travPre()
{rand() % 2 ? travPre_R(this) : travPre_I(this);}

template<typename T>
void BinaryNode<T>::travIn()
{rand() % 2 ? travIn_R(this) : travIn_I(this);}

template<typename T>
void BinaryNode<T>::travPost()
{travPost_R(this);};

//定义一系列内联函数，用做辅助
/******************************************************/
template<typename T>
inline bool IsRoot(BinaryNode<T> const* node)
{return !node->_parent;}

template<typename T>
inline bool IsLeftChild(BinaryNode<T> const* node)
{return !(IsRoot(node)) & (node == node->_parent->_leftChild);}

template<typename T>
inline bool IsRightChild(BinaryNode<T> const* node)
{return !(IsRoot(node)) & (node == node->_parent->_rightChild);}

template<typename T>
inline bool HasParent(BinaryNode<T> const* node)
{return !(IsRoot(node));}

template<typename T>
inline bool HasLeftChild(BinaryNode<T> const* node)
{return node->_leftChild;}

template<typename T>
inline bool HasRightChild(BinaryNode<T> const* node)
{return node->_rightChild;}

template<typename T>
inline bool HasChild(BinaryNode<T> const* node)
{return HasLeftChild(node) || HasRightChild(node);}

template<typename T>
inline bool HasBothChild(BinaryNode<T> const* node)
{return HasLeftChild(node) & HasRightChild(node);}

template<typename T>
inline bool IsLeaf(BinaryNode<T> const* node)
{return !(HasChild(node));}

template<typename T>
inline BinaryNode<T>* Brother(BinaryNode<T> const* node)
{return IsLeftChild(node) ? node->_parent->_rightChild : node->_parent->_leftChild;}

template<typename T>
inline BinaryNode<T>* Uncle(BinaryNode<T> const* node)
{return IsLeftChild(node) ? node->_parent->_parent->_rightChild : node->_parent->_parent->_leftChild;}

template<typename T>
inline BinaryNode<T>*& FromParentToRef(BinaryNode<T>* node)
{return IsRoot(node) ? node : (IsLeftChild(node) ? node->_parent->_leftChild : node->_parent->_rightChild);}

template<typename T>
inline int Height(BinaryNode<T> const* node) 
{return node ? node->_hight : -1;};

/***************************************************/
/***************************************************/

template<typename T>
class BinaryTree
{
    public:
        explicit BinaryTree() : _size(0),_root(NULL){};
        ~BinaryTree(){if(_size > 0) remove(_root);};
        
        int size() const {return _size;};
        bool empty() const {return !_root;};
        BinaryNode<T>* root() const {return _root;};
        BinaryNode<T>* insertAsRoot(T const& elem);
        BinaryNode<T>* insertAsLeftChild(BinaryNode<T>* node,T const& elem);
        BinaryNode<T>* insertAsRightChild(BinaryNode<T>* node,T const& elem);
        BinaryNode<T>* attachAsLeftChild(BinaryNode<T>* node,BinaryTree<T>* tree);
        BinaryNode<T>* attachAsRightChild(BinaryNode<T>* node,BinaryTree<T>* tree);
        int remove(BinaryNode<T>* node);
        BinaryTree<T>* secede(BinaryNode<T>* node);
        void travLevel() const {if(_root) _root->travLevel();};
        void travIn() const {if(_root) _root->travIn();};
        void travPost() const {if(_root) _root->travPost();};
        void travPre() const {if(_root) _root->travPre();};
        bool operator==(BinaryTree<T> const& tree) const {return _root == tree._root;};
        bool operator<(BinaryTree<T> const& tree) const {return _root < tree._root;};

    protected:
        int _size;
        BinaryNode<T>* _root;
        virtual int updateHeight(BinaryNode<T>* node);
        void updateHeightAbove(BinaryNode<T>* node);
};

template<typename T>
inline void release(BinaryTree<T>* tree)
{
    if(tree)
        delete tree;
}

template<typename T>
inline void release(BinaryNode<T>* node)
{
    if(node)
        delete node;
}

template<typename T>
int BinaryTree<T>::updateHeight(BinaryNode<T>* node) 
{return node->_hight = 1 + std::max(Height(node->_leftChild),Height(node->_rightChild));};

template<typename T>
void BinaryTree<T>::updateHeightAbove(BinaryNode<T>* node)
{while(node){updateHeight(node);node = node->_parent;};}

template<typename T>
BinaryNode<T>* BinaryTree<T>::insertAsRoot(T const& elem)
{_size = 1;return _root = new BinaryNode<T>(elem);}

template<typename T>
BinaryNode<T>* BinaryTree<T>::insertAsLeftChild(BinaryNode<T>* node,T const& elem)
{
    _size++;
    node->insertAsLeftChild(elem);
    updateHeightAbove(node);
    return node->_leftChild;
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::insertAsRightChild(BinaryNode<T>* node,T const& elem)
{
    _size++;
    node->insertAsRightChild(elem);
    updateHeightAbove(node);
    return node->_rightChild;
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::attachAsLeftChild(BinaryNode<T>* node,BinaryTree<T>* tree)
{
    if(!node->_leftChild)
    {
        node->_leftChild = tree->_root;
        node->_leftChild->_parent = node;
    }
    _size += tree->_size;
    updateHeightAbove(node);
    tree->_root = NULL;
    tree->_size = 0;
    release(tree);
    tree = NULL;
    return node;
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::attachAsRightChild(BinaryNode<T>* node,BinaryTree<T>* tree)
{
    if(!node->_rightChild)
    {
        node->_rightChild = tree->_root;
        node->_leftChild = tree->_root;
    }
    _size += tree->size;
    updateHeightAbove(node);
    tree->_root = NULL;tree->_size = 0;
    release(tree);
    tree = NULL;
    return node;
}

template<typename T>
int BinaryTree<T>::remove(BinaryNode<T>* node)
{
    FromParentToRef(node) = NULL;
    updateHeightAbove(node->_parent);
    int n = removeAt(node);
    _size -= n;
    return n;
}

template<typename T>
static int removeAt(BinaryNode<T>* node)
{
    if(!node)
        return 0;
    int n = 1 + removeAt(node->_leftChild) + removeAt(node->_rightChild);
    release(node);
    return n;
}

template<typename T>
BinaryTree<T>* BinaryTree<T>::secede(BinaryNode<T>* node)
{
    FromParentToRef(node) = NULL;
    updateHeightAbove(node->_parent);
    BinaryTree<T>* tree = new BinaryTree<T>;
    tree->_root = node;
    node->_parent = NULL;
    tree->_size = node->size();
    _size -= tree->_size;
    return tree;
}

#endif
