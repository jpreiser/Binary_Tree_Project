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
    /* Constructur of the binary tree. */
    BinaryTree();

    /* Destructor for the binary tree. */
    ~BinaryTree();

    /* Inserts a node into the tree. */
    void insert(T &key);

    /* Deletes an item from the tree and restructures the tree as needed. */
    void deleteItem(T &key);

    /* If an item exists in the tree, return it and set found to true if successful. */
    void retrieve(T &item, bool &found) const;

    /* Prints the preorder of the tree. */
    void preOrder() const;

    /* Prints the values of the tree in order. */
    void inOrder() const;

    /* Prints the post-order of the tree. */
    void postOrder() const;

    /* Returns the number of nodes in the tree. */
    int getLength() const;

    /* Returns the number of nodes with only a single child. */
    int getNumSingleParent();

    /* Returns the number of leaf nodes within the tree. */
    int getNumLeafNodes();

    /* Returns the sum of the subtrees of a given node */
    void getSumOfSubtrees();

    /* The root of the tree */  
    NodeType *root;
};

#endif