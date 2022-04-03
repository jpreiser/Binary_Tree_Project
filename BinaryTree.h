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

    /* Recursive function for deleting a tree. */
    NodeType<T>* makeEmpty(NodeType<T>* n);

    /* Inserts a node into the tree. */
    void insert(T key);

    /* Insert Overload for recursive calls. */
    NodeType<T>* insert(NodeType<T> *node, T key);

    /* Deletes an item from the tree and restructures the tree as needed. */
    void deleteItem(T key);

    /* Recursive overload to delete an item from the tree. */
    NodeType<T>* deleteItem(T key, NodeType<T>* n);

    /* If an item exists in the tree, return it and set found to true if successful. */
    void retrieve(T key, bool found);

    /* Recursive call for finding if a node exists in the tree. */
    bool retrieve(NodeType<T>* n, T key);

    /* Prints the preorder of the tree. */
    void preOrder(NodeType<T>* node) const;

    /* Prints the values of the tree in order. */
    void inOrder(NodeType<T>* node) const;

    /* Prints the post-order of the tree. */
    void postOrder(NodeType<T>* node) const;

    /* Returns the number of nodes in the tree. */
    int getLength(NodeType<T>* node) const;

    /* Returns the number of nodes with only a single child. */
    int getNumSingleParent(NodeType<T>* n);

    /* Returns the number of leaf nodes within the tree. */
    int getNumLeafNodes(NodeType<T>* n);

    /* Returns the sum of the subtrees of a given node */
    void getSumOfSubtrees(NodeType<T>* n, T key);
    
    /* Recursive call used by sum of subtrees once subtree root is found. */
    T getVal(NodeType<T>* n);

    /* Recursive function to find the max value in a tree or subtree. */
    NodeType<T>* findMax(NodeType<T>* node);

    /* Recursive function to find teh min value in a tree or subtree. */
    NodeType<T>* findMin(NodeType<T>* node);
};

#endif