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
    } else if (key < n->key) {
        n->left = insert(n->left, key);
    } else if (key > n->key) {
        n->right = insert(n->right, key);
    } else if (key == n->key) {
        std::cout << "Item already in tree." << std::endl;
    }   
    return n;
}

/* Deletes an item from the tree and restructures the tree as needed. */
template<class T>
void BinaryTree<T>::deleteItem(T key) {
     root = deleteItem(key, root);
}

/* Recursive Overload for deleting an item from the tree. */
template<class T>
NodeType<T>* BinaryTree<T>::deleteItem(T key, NodeType<T>* n) {
    NodeType<T>* temp;
    if(n == NULL) {
        return NULL;
    } else if(key < n->key) {
        n->left = deleteItem(key, n->left);
    } else if(key > n->key) {
        n->right = deleteItem(key, n->right);
    } else if(n->left && n->right) {
        temp = findMin(n->right);
        n->key = temp->key;
        n->right = deleteItem(n->key, n->right);
    } else {
        temp = n;
        if(n->left == NULL)
            n = n->right;
        else if(n->right == NULL)
            n = n->left;
        delete temp;
    }
    return n;
}

/* If an item exists in the tree, return it and set found to true if successful. */
template<class T>
void BinaryTree<T>::retrieve(T key, bool found) {
    if (retrieve(root, key) == true) {
        found = true;
    }
    if (found == true) {
        std::cout << "Item found in tree." << std::endl;
    } else {
        std::cout << "Item not in tree." << std::endl;
    }
}

/* Overload of retrieve. */
template<class T>
bool BinaryTree<T>::retrieve(NodeType<T>* n, T key) {
    bool inTree;
    if (n == NULL) {
        inTree = false;
    } else if (n->key == key) {
        inTree = true;
    } else if (key < n->key) {
        retrieve(n->left, key);
    } else if (key > n->key) {
        retrieve(n->right, key);
    }
    return inTree;
}

/* Prints the preorder of the tree. */
template<class T>
void BinaryTree<T>::preOrder(NodeType<T>* node) const {
    if (node != NULL) {
        std::cout << node->key << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

/* Prints the values of the tree in order. */
template<class T>
void BinaryTree<T>::inOrder(NodeType<T>* node) const{
    if (node != NULL) {
        inOrder(node->left);
        std::cout << node->key << " ";
        inOrder(node->right);
    }
}

/* Prints the post-order of the tree. */
template<class T>
void BinaryTree<T>::postOrder(NodeType<T>* node) const {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        std::cout << node->key << " ";
    }
}

/* Returns the number of nodes in the tree. */
template<class T>
int BinaryTree<T>::getLength(NodeType<T>* node) const {
    if (node == NULL) {
        return 0;
    } else {
        return getLength(node->left) + getLength(node->right) + 1; 
    }
    std::cout << " ... " << std::endl;
}

/* Returns the number of nodes with only a single child. */
template<class T>
int BinaryTree<T>::getNumSingleParent(NodeType<T>* n) {
    if (n == NULL) {
        return 0; 
    } 
    if ((n->left != NULL && n->right == NULL) || (n->left == NULL && n->right != NULL)) {
        return getNumSingleParent(n->left) + getNumSingleParent(n->right) + 1;
    } else {
        return getNumSingleParent(n->left) + getNumSingleParent(n->right);
    }
}

/* Returns the number of leaf nodes within the tree. */
template<class T>
int BinaryTree<T>::getNumLeafNodes(NodeType<T>* n) {
    if (n == NULL) {
        return 0; 
    } 
    if (n->left == NULL && n->right == NULL) {
        return getNumLeafNodes(n->left) + getNumLeafNodes(n->right) + 1;
    } else {
        return getNumLeafNodes(n->left) + getNumLeafNodes(n->right);
    } 
}

/* Returns the sum of the subtrees of a given node */
template<class T>
void BinaryTree<T>::getSumOfSubtrees(NodeType<T>* n, T key) {
    try {
        T total;
        if (n == NULL) {
            std::cout << "Item not in tree." << std::endl;
            return;
        }
        if (n->key == key) {
            total = getVal(n->left) + getVal(n->right);
            std::cout << "Sum of Subtrees: " << total << std::endl; 
            return;
        } else if (key < n->key) {
            getSumOfSubtrees(n->left, key);
        } else if (key > n->key) {
            getSumOfSubtrees(n->right, key);
        }
    }
    catch (std::logic_error&) {
        std::cout << "Can't sum strings." << std::endl;
    }

}

template<class T>
T BinaryTree<T>::getVal(NodeType<T>* n) {
    if (n == NULL) {
        return 0;
    }
    T sum = n->key; 
    if (n->left != NULL) {
        sum = sum + getVal(n->left);
    } 
    if (n->right != NULL) {
        sum = sum + getVal(n->right);
    }
    return sum;
}

/* Recursive function to find the max value in a tree or subtree. */
template<class T>
NodeType<T>* BinaryTree<T>::findMax(NodeType<T>* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->right == NULL) {
        return node;
    } else {
        return findMax(node->right);
    }
}

/* Recursive function to find teh min value in a tree or subtree. */
template<class T>
NodeType<T>* BinaryTree<T>::findMin(NodeType<T>* node) {
    if (node == NULL) {
        return NULL;
    } else if (node->left == NULL) {
        return node;
    } else {
        return findMin(node->left);
    }
}

template class BinaryTree<int>;
template class BinaryTree<float>;
template class BinaryTree<std::string>;