/*************************************************************************
	> File Name: binaryTree.cc
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月16日 星期五 20时04分31秒
 ************************************************************************/

#include<iostream>
#include"binaryTree.h"
#include"../4/stack.h"

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
inline BinaryNode<T>* FromParentToRef(BinaryNode<T> const* node)
{return IsRoot(node) ? node : (IsLeftChild(node) ? node->_parent->_leftChild : node->_parent->_rightChild);}

template<typename T>
inline int Height(BinaryNode<T> const* node) 
{return node ? node->_hight : 0;};

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
BinaryNode<T>* BinaryNode<T>::insertAsLeftChild(T const& elem)
{return _leftChild = new BinaryNode(elem,this);}

template<typename T>
BinaryNode<T>* BinaryNode<T>::insertAsRightChild(T const& elem)
{return _rightChild = new BinaryNode(elem,this);}

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
void travIn_R(BinaryNode<T>* node)
{
    if(node)
    {
        travIn_R(node->_leftChild);
        std::cout << node->_data << std::endl;
        travIn_R(node->_rightChild);
    }
}

template<typename T>
void travPost_R(BinaryNode<T>* node)
{
    if(node)
    {
        travPost_R(node->_leftChild);
        travPost_R(node->_rightChild);
        std::cout << node->_data << std::endl;
    }
}

template<typename T>
void travPre_R(BinaryNode<T>* node)
{
    if(node)
    {
        std::cout << node->_data << std::endl;
        travPre_R(node->_leftChild);
        travPre_R(node->_rightChild);
    }
}

template<typename T>
void travPre_I(BinaryNode<T>* node)
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
void travIn_I(BinaryNode<T>* node)
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
void travPost_I(BinaryNode<T>* node)
{
    Stack<BinaryNode<T>*> BinaryNodeStack;
    
    while(1)
    {
        while(node)
        {
             
        }
    }

}






























