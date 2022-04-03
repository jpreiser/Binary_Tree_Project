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
    insert(root, key);
}

/* Recursive Function for putting items into a tree. */
template<class T>
NodeType<T>* BinaryTree<T>::insert(NodeType<T>* node, T key) {
    if (node == NULL) {
        node = new NodeType<T>;
        node->right = NULL;
        node->left = NULL;
        node->key = key;
    } else if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right = insert(node->right, key);
    }
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
        std::cout << "Pre-Order: ";
        std::cout << node->key;
        preOrder(node->left);
        preOrder(node->right);
    }
    std::cout << "" << std::endl;
}

/* Prints the values of the tree in order. */
template<class T>
void BinaryTree<T>::inOrder(NodeType<T>* node) const{
    if (node != nullptr) {
        std::cout << "In-Order: ";
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
    std::cout << std::endl; 
}

/* Prints the post-order of the tree. */
template<class T>
void BinaryTree<T>::postOrder(NodeType<T>* node) const {
    if (node != nullptr) {
        std::cout << "Post-Order";
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }
    std::cout << "" << std::endl;
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

}

/* Returns the number of leaf nodes within the tree. */
template<class T>
int BinaryTree<T>::getNumLeafNodes() {

}

/* Returns the sum of the subtrees of a given node */
template<class T>
void BinaryTree<T>::getSumOfSubtrees(T key) {

}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;