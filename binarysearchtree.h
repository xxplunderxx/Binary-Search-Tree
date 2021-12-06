/* 	Jacob Eul
	z1892587
	CSCI 340 3
	
	I certify that this is my own work and where appropriate an extension 
    of the starter code provided for the assignment.
*/

#include "node.h"
#include "btree.h"

#ifndef H_BINARYSEARCHTREE
#define H_BINARYSEARCHTREE

template <typename T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    void Insert(const T &x);       // inserts node with value x
    bool Search(const T &x) const; // searches leaf with value x
    bool Remove(const T &x);       // removes leaf with value x
private:
    void _Insert(Node<T> *&, const T &);      // private version of insert
    bool _Search(Node<T> *, const T &) const; // private version of search
    void _Remove(Node<T> *&, const T &);      // private version of remove
    bool _Leaf(Node<T> *node) const;          // checks if node is leaf
};

/************************************************************************
 *                       Public Member definitions
***********************************************************************/

/***************************************************
 * This function inserts a node with data value x
 * This function will call the private member to preform the operation
 *
 * @param x represents value to be inserted into tree
 ***************************************************/
template<typename T>
void BinarySearchTree<T>::Insert(const T &x)
{
    _Insert(this->root,x);
}

/***************************************************
 * This function searches for the data value x
 * this function will call the private member to perform the operation
 *
 * @param x represents value to search in the tree
 * 
 * @return boolean value to show if search was successful
 ***************************************************/
template<typename T>
bool BinarySearchTree<T>::Search(const T &x) const
{
    return _Search(this->root,x);
}

/***************************************************
 * This function is used to remove a node with value x
 * This funciton will call the search() function to determine if a given node is in the tree & if successful it will call the private member to perform the operation
 *
 * @param x represents value to be removed from the tree
 * 
 * @return boolean value to show if the removal was successful
 ***************************************************/
template<typename T>
bool BinarySearchTree<T>::Remove(const T &x)
{
    //if search of x is true
    if (Search(x))
    {
        //remove x from tree
        _Remove(this->root,x);
        return true;
    }

	return false;
}      

/************************************************************************
 *                       Private Member definitions
***********************************************************************/

/***************************************************
 * This function inserts a new node with data value value
 * This function will check to see where the new node should go, and then insert it
 *
 * @param node represents the node
 * @param value represents the value to be inserted
 ***************************************************/
template<typename T>
void BinarySearchTree<T>::_Insert(Node<T> *&node, const T &value)
{
    // base case
    if(node == nullptr)
    {
        node = new Node<T>(value);      // create a new node at that location
    }

    // check if the current node is greater than the data value
    else if(value < node->data)
    {   
        _Insert(node->left,value);      // insert on the left side since data is less than
    }

    // check if the current node is less than the data value
    else if(value > node->data)
    {
        _Insert(node->right,value);     // insert on the right side since the data is greater than
    }

    else
    {
        return; // leave function
    }
}

/***************************************************
 * This function is used to search a binary search tree
 * This function will traverse the tree to find the node efficeintly
 *
 * @param node represents the node to search from 
 * @param value represents the value to search for 
 * 
 * @return boolean value to represent if the search was successful
 ***************************************************/
template<typename T>
bool BinarySearchTree<T>::_Search(Node<T> *node, const T &value) const
{
    //if node dosn't exisit
	if (node == nullptr)
		return false;

    //check if value is less than the data in node
    else if (value < node->data)
    {
        //return result of search of left tree
        return _Search(node->left, value);
    }

    // value must be greater
    else if (value > node->data)
    {
        //return result of search of right tree
        return _Search(node->right, value);
    }
    
    //check if node is a leaf
    if (_Leaf(node))
    {
        return true;
    }
    else
    {
        return false;
    }
            
}

/***************************************************
 * This function is used to remove a data value value
 * Function will delete the node containing the data value value
 *
 * @param x represents a node to start removing from
 * @param value represents the value to remove
 ***************************************************/
template<typename T>
void BinarySearchTree<T>::_Remove(Node<T> *& node, const T & x)
{
   // base case
    if (node == NULL)
        return;
    
    // If the x to be deleted
    // is smaller than the node's
    // x, then it lies in left subtree
    if (x < node->data)
        _Remove(node->left, x);
 
    // If the x to be deleted
    // is greater than the root's
    // x, then it lies in right subtree
    else if (x > node->data)
        _Remove(node->right, x);
 
    // if x is same as root's x,
    // then This is the node
    // to be deleted
    else if (x == node->data){
        delete node;
        node = nullptr;
    }
}

/***************************************************
 * This function simply checks if a node is a leaf
 * This function will return a bool to be used in other member functions
 *
 * @param x represents node to be tested
 * 
 * @return boolean value to show if the node is a leaf
 ***************************************************/
template<typename T>
bool BinarySearchTree<T>::_Leaf(Node<T> *x) const
{
    // if both right and left child are empty
    if (x->right == nullptr && x->left == nullptr)
    {
        return true;        // it is a leaf
    }

    else
        return false;       // it is not a leaf
}

#endif









