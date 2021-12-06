/* 	Jacob Eul
	z1892587
	CSCI 340 3
	
	I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/

#include "node.h"
#include <algorithm>

#ifndef H_BTREE
#define H_BTREE

template <typename T> class BinaryTree{

public:
    BinaryTree();                                      // default constructor
    unsigned     getSize() const;                      // returns size of tree
    unsigned     getHeight() const;                    // returns height of tree
    virtual void Insert(const T&);                     // inserts node in tree
    void         Inorder(void (*)(const T&));          // inorder traversal of tree

    typedef enum {left_side, right_side } SIDE;        // rnd funciton definiton
    SIDE rnd(){ 
    return std::rand()%2 ? right_side : left_side;
    }

protected:
    Node<T> *root;                                      // root of tree

private:
    unsigned _getSize(Node<T> *) const;                 // private version of getSize()
    unsigned _getHeight(Node<T> *) const;               // private version of getHeight()
    void     _Insert(Node<T> *&, const T&);             // private version of Insert()
    void     _Inorder(Node<T> *, void (*)(const T&));   // private version of Inorder()
};

/************************************************************************
 *                       Public Member definitions
***********************************************************************/

/***************************************************
 * This is a default constuctor
 ***************************************************/
template<typename T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;        // set root node as NULL
}

/***************************************************
 * This funciton gets the size of the binary tree
 * This function will simply call its private version
 *
 * @return unsigned value representing size of tree
 ***************************************************/
template<typename T>
unsigned BinaryTree<T>::getSize() const
{
    // call the private version of this function
    return _getSize(this -> root);
}

/***************************************************
 * This funciton gets the height of the binary tree
 * this function will simply call its private member function
 * 
 * @return unsigned value representing hieght of tree
 ***************************************************/
template<typename T>
unsigned BinaryTree<T>::getHeight() const
{
    // call the private version of this function
    return _getHeight(this -> root);
}

/***************************************************
 * A virtual function used to insert a new node
 * this function will simply call the private member funciton
 *
 * @param x represents value to be inserted into tree
 ***************************************************/
template<typename T>
void BinaryTree<T>::Insert(const T &x)
{
    // call the private version of this function
    _Insert(this -> root, x);
}

/***************************************************
 * Function is used to preform inorder traversal
 * this functino will simply call the private member function
 *
 * @param c represents a function that will be called from main
 ***************************************************/
template<typename T>
void BinaryTree<T>::Inorder(void (*c)(const T&))
{
    _Inorder(this -> root, c);  // call private version
}

/************************************************************************
 *                       Private Member definitions
***********************************************************************/

/***************************************************
 * This funciton gets the size of the binary tree
 * This function will determine the size of a tree given a node
 *
 * @param x represents a pointer to the node to get the size from
 * 
 * @return returns an unsigned integer representing size
 ***************************************************/
template<typename T>
unsigned BinaryTree<T>::_getSize(Node<T> *x) const
{
    // return 0 upon reaching the leaf node
    if (x == NULL)
    {
        return 0;
    }

    // recursive call to left and right subtree (adds one for each node entered)
    return (_getSize(x->left) + 1 + _getSize(x->right));  
} 

/***************************************************
 * This funciton gets the height of the binary tree
 * This function will determine the height of a tree given a node
 *
 * @param x represents a pointer to the node to get the height from
 * 
 * @return returns an unsigned integer representing height
 ***************************************************/
template<typename T>
unsigned BinaryTree<T>::_getHeight(Node<T> *x) const
{
    // return 0 upon reaching a leaf node
    if (x == NULL)
    {
        return 0;
    }

    // recursive call to the max of left and right subtree (counts 1 for each new height)
    return (std::max(_getHeight(x->left), _getHeight(x->right)) + 1);
} 

/***************************************************
 * A virtual function used to insert a new node
 * This function will insert a new node into the binary tree
 *
 * @param value represents the value to be inserted
 * @param x represents the node
 ***************************************************/
template<typename T>
 void BinaryTree<T>::_Insert(Node<T> *& x, const T& value)
 {
     // if node is empty create a new node
     if (x == NULL)
    { 
        x = new Node<T>();
        x -> data = value;
        x -> right = x -> left = NULL;
    }

    /** otherwise choose right || left side **/

    // if right side
    else if (rnd() == right_side)
    {
        _Insert(x->right, value); 
    }
    // otherwise assume it is the left side
    else
    {
        _Insert(x->left, value);
    }
 }

/***************************************************
 * Function is used to preform inorder traversal
 * This function will perform the inorder traveral on a tree
 *
 * @param x represents the starting node to perfrom inorder traversal
 * @param c represents a function that is passed as an arugement (print)
 ***************************************************/
template<typename T>
void BinaryTree<T>::_Inorder(Node<T> *x , void (*c)(const T&))
{
    // while not leaf node
    if (x != NULL)
    {
        _Inorder(x->left, c);      // left child
        c(x->data);                // node
        _Inorder(x->right, c);     // right child
    }
}

#endif // End of H_BTREE
