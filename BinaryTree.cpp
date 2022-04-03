#include <cstdlib>
#include <iostream>
#include "BinaryTree.h"

/* Constructur of the binary tree. */
template<class T>
BinaryTree<T>::BinaryTree() {
    root = NULL;
}

/* Destructor for the binary tree. */
template<class T>
BinaryTree<T>::~BinaryTree() {

}

/* Inserts a node into the tree. */
template<class T>
void BinaryTree<T>::insert(T key) {
    root = insert(root, key);
}

/* Recursive Function for putting items into a tree. */
template<class T>
NodeType<T>* BinaryTree<T>::insert(NodeType<T>* n, T key) {
    if (n == NULL) {
        n = new NodeType<T>;
        n->key = key;
        n->left = n->right = NULL;
    }   
    else if (key < n->key) {
        n->left = insert(n->left, key);
    } else if (key > n->key) {
        n->right = insert(n->right, key);
    }
    return n;
}

/* Deletes an item from the tree and restructures the tree as needed. */
template<class T>
void BinaryTree<T>::deleteItem(T key) {

}

/* If an item exists in the tree, return it and set found to true if successful. */
template<class T>
void BinaryTree<T>::retrieve(T item, bool found) const {

}

/* Prints the preorder of the tree. */
template<class T>
void BinaryTree<T>::preOrder(NodeType<T>* node) const {
    if (node != nullptr) {
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

/* Prints the values of the tree in order. */
template<class T>
void BinaryTree<T>::inOrder(NodeType<T>* node) const{
    if (node != nullptr) {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

/* Prints the post-order of the tree. */
template<class T>
void BinaryTree<T>::postOrder(NodeType<T>* node) const {
    if (node != nullptr) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }
}

/* Returns the number of nodes in the tree. */
template<class T>
int BinaryTree<T>::getLength(NodeType<T>* node) const {
    if (node == nullptr) {
        return 0;
    } else {
        return getLength(node->left) + getLength(node->right) + 1; 
    }
}

/* Returns the number of nodes with only a single child. */
template<class T>
int BinaryTree<T>::getNumSingleParent() {
    return 0; 
}

/* Returns the number of leaf nodes within the tree. */
template<class T>
int BinaryTree<T>::getNumLeafNodes() {
    return 0; 
}

/* Returns the sum of the subtrees of a given node */
template<class T>
void BinaryTree<T>::getSumOfSubtrees(T key) {
    std::cout << "0" << std::endl;
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;