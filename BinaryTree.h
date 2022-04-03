#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstdlib>
#include <iostream>

template<class T>
struct NodeType {
    T key;
    NodeType<T>* left;
    NodeType<T>* right;

}; // node

template<class T>
class BinaryTree {
public:
    /* The root of the tree */  
    NodeType<T>* root;

    /* Constructur of the binary tree. */
    BinaryTree();

    /* Destructor for the binary tree. */
    ~BinaryTree();

    /* Inserts a node into the tree. */
    void insert(T key);

    /* Insert Overload for recursive calls. */
    NodeType<T>* insert(NodeType<T> *node, T key);

    /* Deletes an item from the tree and restructures the tree as needed. */
    void deleteItem(T key);

    /* If an item exists in the tree, return it and set found to true if successful. */
    void retrieve(T item, bool found) const;

    /* Prints the preorder of the tree. */
    void preOrder(NodeType<T>* node) const;

    /* Prints the values of the tree in order. */
    void inOrder(NodeType<T>* node) const;

    /* Prints the post-order of the tree. */
    void postOrder(NodeType<T>* node) const;

    /* Returns the number of nodes in the tree. */
    int getLength(NodeType<T>* node) const;

    /* Returns the number of nodes with only a single child. */
    int getNumSingleParent();

    /* Returns the number of leaf nodes within the tree. */
    int getNumLeafNodes();

    /* Returns the sum of the subtrees of a given node */
    void getSumOfSubtrees(T key);

};

#endif