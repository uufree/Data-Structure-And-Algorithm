/*************************************************************************
	> File Name: RBTree.h
	> Author: uuchen
	> Mail: 1319081676@qq.com
	> Created Time: 2018年03月21日 星期三 17时02分00秒
 ************************************************************************/

#ifndef _RBTREE_H
#define _RBTREE_H

#include"binarySearchTree.h"

template<typename T>
class RBTree : public BinarySearchTree<T>
{
    public:
        BinaryNode<T>* insert(T const& elem);
        bool remove(T const& elem); 

    protected:
        void sloveDoubleRed(BinaryNode<T>* node);
        void sloveDoubleBlack(BinaryNode<T>* node);
        void updateHeight(BinaryNode<T>* node);
};

template<typename T>
static inline bool IsBlack(BinaryNode<T> const* node){return !(node) || node->_color == RB_BLACK;};

template<typename T>
static inline bool IsRed(BinaryNode<T> const* node){return !IsBlack(node);};

template<typename T>
static inline bool BlackHeightUpdate(BinaryNode<T> const* node)
{return Height((node->_leftChild)  == Height(node->_rightChild) && node->_color == IsRed(node)) ? Height(node->_leftChild) : Height(node->_rightChild);};

template<typename T>
void RBTree<T>::updateHeight(BinaryNode<T>* node)
{
    node->_hight = std::max(Height(node->_leftChild),Height(node->_rightChild));
    return IsBlack(node) ? node->_hight++ : node->_hight;
}

template<typename T>
BinaryNode<T>* RBTree<T>::insert(T const& elem)
{
    BinaryNode<T>*& node = search(elem);
    if(node)
        return node;
    node = new BinaryNode<T>(elem,BinarySearchTree<T>::_hot,NULL,NULL,-1);
    BinarySearchTree<T>::_size++;
    sloveDoubleRed(node);
    return node ? node : BinarySearchTree<T>::_hot->_parent;
}

template<typename T>
bool RBTree<T>::remove(T const& elem)
{
    BinaryNode<T>*& node = search(elem);
    if(!node)
        return false;
    
    BinaryNode<T>* d_node = removeAt(elem,BinarySearchTree<T>::_hot);
    if(!(--BinarySearchTree<T>::_size))
        return true;
    if(!BinarySearchTree<T>::_hot)
    {
        BinarySearchTree<T>::_root->_color = RB_BLACK;
        updateHeight(BinarySearchTree<T>::_root);
        return true;
    }
    
    if(BlackHeightUpdate(BinarySearchTree<T>::_root))
        return true;
    if(IsRed(node))
    {
        node->_color = RB_BLACK;
        node->_hight++;
        return true;
    }

    sloveDoubleBlack(node);
}

template<typename T>
void RBTree<T>::sloveDoubleRed(BinaryNode<T>* node)
{
    if(IsRoot(node))
    {
        BinarySearchTree<T>::_root = RB_BLACK;
        BinarySearchTree<T>::_root->_hight++;
        return;
    }
    BinaryNode<T>* parent = node->_parent;
    BinaryNode<T>* g_parent = parent->_parent;
    BinaryNode<T>* uncle = Uncle(node);
    
    if(IsBlack(uncle))
    {
        if(IsLeftChild(parent) & IsLeftChild(node))
            parent->_color = RB_BLACK;
        else
            node->_parent = RB_BLACK;
        g_parent->_color = RB_RED;
        BinaryNode<T>* gg_parent = g_parent->_parent;
        BinaryNode<T>* newNode = FromParentRef(g_parent) = rotateAt(node);
        newNode->_parent = gg_parent;
    }
    else
    {
        parent->_color = RB_BLACK;parent->_hight++;
        uncle->_color = RB_BLACK;uncle->_hight++;
        if(!IsRoot(g_parent))
            g_parent->_color = RB_RED;
        sloveDoubleRed(g_parent);
    }
}

template<typename T>
void RBTree<T>::sloveDoubleBlack(BinaryNode<T>* node)
{
    BinaryNode<T>* p_node = node ? node->_parent : BinarySearchTree<T>::_hot;
    BinaryNode<T>* b_node = (node == p_node->_leftChild) ? p_node->_rightChild : p_node->_leftChild;
    
    if(IsBlack(b_node))
    {
        BinaryNode<T>* bc_node = IsRed(b_node->_leftChild) ? b_node->_leftChild : b_node->_rightChild;
        if(bc_node)
        {
            RBColor p_nodeColor = p_node->_color;
            BinaryNode<T>* newNode = FromParentRef(p_node) = rotateAt(bc_node);
            if(HasLeftChild(newNode))
            {
                newNode->_leftChild->_color = RB_BLACK;
                updateHeight(newNode->_hight);
            }
            if(HasRightChild(newNode))
            {
                newNode->_rightChild->_color = RB_BLACK;
                updateHeight(newNode->_rightChild);
            }
            newNode->_color = p_nodeColor;
            updateHeight(newNode);
        }
        else
        {
            b_node->_color = RB_RED;
            b_node->_hight--;
            if(IsRed(p_node))
                p_node->_color = RB_BLACK;
            else
            {
                p_node->_hight--;
                sloveDoubleBlack(p_node);
            }
        }
                    
    }
    else
    {
        b_node->_color = RB_BLACK;
        p_node->_color = RB_RED;
        BinaryNode<T>* newNode = IsLeftChild(b_node) ? b_node->_rightChild : b_node->_leftChild;
        BinarySearchTree<T>::_hot = p_node;
        FromParentRef(p_node) = rotateAt(newNode);
        updateHeight(node);
    }
}







#endif
