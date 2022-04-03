#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>
#include <iterator>
#include <vector>
#include "BinaryTree.h"

void printGreeting() {
    std::cout << "Enter tree type (i - int, f - float, s - std::string): ";
}

void printOptions() {
    std::cout << "Commands:" << std::endl;
    std::cout << "insert (i), delete (d), retrieve (r), length (l), in-order (n)," << std::endl;
    std::cout << "pre-order (p), post-order(o), getNumSingleParent (s)," << std::endl;
    std::cout << "getNumLeafNodes (f), getSumOfSubtrees (t), quit (q)" << std::endl;
}

BinaryTree<int> createIntTree(std::string fileName) {

    std::ifstream sFile(fileName.c_str());
	std::vector<int> vals;
	int num;
	BinaryTree<int> created = BinaryTree<int>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}

	while (sFile >> num) {
		vals.push_back(num);
	}

	for(long unsigned int i = 0; i < vals.size(); i++) {
        num = vals.at(i);
		created.insert(num);
	}
	sFile.close();
	return created;

} // createIntTree

BinaryTree<float> createFloatTree(std::string fileName) {

    std::ifstream sFile(fileName.c_str());
	std::vector<float> vals;
	float num;
	BinaryTree<float> created = BinaryTree<float>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}

	for(long unsigned int i = 0; i < vals.size(); i++) {
        num = vals.at(i);
		created.insert(num);
	}
	sFile.close();
	return created;

} // createFloatTree

BinaryTree<std::string> createStringTree(std::string fileName) {
    std::ifstream sFile(fileName.c_str());
	std::vector<std::string> vals;
	std::string num;
	BinaryTree<std::string> created = BinaryTree<std::string>();

	if (!sFile.is_open()) {
		std::cout << "File not found" << std::endl;
	}
	while (sFile >> num) {
		vals.push_back(num);
	}

	for(long unsigned int i = 0; i < vals.size(); i++) {
        num = vals.at(i);
		created.insert(num);
	}
	sFile.close();
	return created;

} // createStringTree


void intTree(BinaryTree<int> tree) {

    int key;
    char operation;

    while(1) { 
        std::cout << "Enter a command: ";
        std::cin >> operation;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(operation) {
        case 'i': // insert *done*
            std::cout << "Item to insert: ";
            std::cin >> key;
            tree.BinaryTree<int>::insert(key);
            std::cout << "In-Order: ";
            tree.BinaryTree<int>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'd': // delete *done*
            std::cout << "Item to delete: ";
            std::cin >> key;
            tree.BinaryTree<int>::deleteItem(key);
            std::cout << "In-Order: ";
            tree.inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'r': {// retrieve *done*
            bool found = false;
            std::cout << "Item to be retrieved: ";
            std::cin >> key;
            tree.BinaryTree<int>::retrieve(key, found);
            break;
        }
        case 'l': // length *done*
            std::cout << "Tree Length: ";
            std::cout << tree.BinaryTree<int>::getLength(tree.root) << std::endl;
            break;
        case 'n': // in order *done*
            std::cout << "In-Order: ";
            tree.BinaryTree<int>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'p': // pre-order *done*
            std::cout << "Pre-Order: ";
            tree.BinaryTree<int>::preOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'o': // post-order *done*
            std::cout << "Post-Order: ";
            tree.BinaryTree<int>::postOrder(tree.root);
            std::cout << std::endl;
            break;
        case 's': // getNumSingleParent *done*
            std::cout << "Number of Single Parents: ";
            std:: cout << tree.BinaryTree<int>::getNumSingleParent(tree.root);
            std::cout << std::endl;
            break;
        case 'f': // getNumLeafNodes *done*
            std::cout << "Number of leaf nodes: ";
            std::cout << tree.BinaryTree<int>::getNumLeafNodes(tree.root);
            std::cout << std::endl;
            break;
        case 't': // getSumOfSubtrees *done*
            std::cout << "Item to get sum of subtrees: ";
            std::cin >> key;
            tree.BinaryTree::getSumOfSubtrees(tree.root, key);
            break;
        case 'q': // quit *done*
            std::cout << "Quitting program..." << std::endl;
            return;
        default:
            std::cout << "Command not recognized. Try again" << std::endl;
            break;    
        }
    }

} // intTree option

void floatTree(BinaryTree<float> tree) {
    float key;
    char operation;

    while(1) { 
        std::cout << "Enter a command: ";
        std::cin >> operation;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(operation) {
        case 'i': // insert *done*
            std::cout << "Item to insert: ";
            std::cin >> key;
            tree.BinaryTree<float>::insert(key);
            std::cout << "In-Order: ";
            tree.BinaryTree<float>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'd': // delete *done*
            std::cout << "Item to delete: ";
            std::cin >> key;
            tree.BinaryTree<float>::deleteItem(key);
            tree.inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'r': {// retrieve *done*
            bool found = false;
            std::cout << "Item to be retrieved: ";
            std::cin >> key;
            tree.BinaryTree<float>::retrieve(key, found);
            break;
        }
        case 'l': // length *done*
            std::cout << "Tree Length: ";
            std::cout << tree.BinaryTree<float>::getLength(tree.root) << std::endl;
            break;
        case 'n': // in order *done*
            std::cout << "In-Order: ";
            tree.BinaryTree<float>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'p': // pre-order *done*
            std::cout << "Pre-Order: ";
            tree.BinaryTree<float>::preOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'o': // post-order *done*
            std::cout << "Post-Order: ";
            tree.BinaryTree<float>::postOrder(tree.root);
            std::cout << std::endl;
            break;
        case 's': // getNumSingleParent *done*
            std::cout << "Number of Single Parents: ";
            std:: cout << tree.BinaryTree<float>::getNumSingleParent(tree.root);
            std::cout << std::endl;
            break;
        case 'f': // getNumLeafNodes *done*
            std::cout << "Number of leaf nodes: ";
            std::cout << tree.BinaryTree<float>::getNumLeafNodes(tree.root);
            std::cout << std::endl;
            break;
        case 't': // getSumOfSubtrees *done*
            std::cout << "Item to get sum of subtrees: ";
            std::cin >> key;
            tree.BinaryTree::getSumOfSubtrees(tree.root, key);
            break;
        case 'q': // quit *done*
            std::cout << "Quitting program..." << std::endl;
            return;
        default:
            std::cout << "Command not recognized. Try again" << std::endl;
            break;    
        }
    }

} // floatTree options

void stringTree(BinaryTree<std::string> tree) {

    std::string key;
    char operation;

    while(1) { 
        std::cout << "Enter a command: ";
        std::cin >> operation;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        switch(operation) {
        case 'i': // insert *done*
            std::cout << "Item to insert: ";
            std::cin >> key;
            tree.BinaryTree<std::string>::insert(key);
            std::cout << "In-Order: ";
            tree.BinaryTree<std::string>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'd': // delete *done*
            std::cout << "Item to delete: ";
            std::cin >> key;
            tree.BinaryTree<std::string>::deleteItem(key);
            std::cout << "In-Order: ";
            tree.inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'r': {// retrieve *done*
            bool found = false;
            std::cout << "Item to be retrieved: ";
            std::cin >> key;
            tree.BinaryTree<std::string>::retrieve(key, found);
            break;
        }
        case 'l': // length *done*
            std::cout << "Tree Length: ";
            std::cout << tree.BinaryTree<std::string>::getLength(tree.root) << std::endl;
            break;
        case 'n': // in order *done*
            std::cout << "In-Order: ";
            tree.BinaryTree<std::string>::inOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'p': // pre-order *done*
            std::cout << "Pre-Order: ";
            tree.BinaryTree<std::string>::preOrder(tree.root);
            std::cout << std::endl;
            break;
        case 'o': // post-order *done*
            std::cout << "Post-Order: ";
            tree.BinaryTree<std::string>::postOrder(tree.root);
            std::cout << std::endl;
            break;
        case 's': // getNumSingleParent *done*
            std::cout << "Number of Single Parents: ";
            std:: cout << tree.BinaryTree<std::string>::getNumSingleParent(tree.root);
            std::cout << std::endl;
            break;
        case 'f': // getNumLeafNodes *done*
            std::cout << "Number of leaf nodes: ";
            std::cout << tree.BinaryTree<std::string>::getNumLeafNodes(tree.root);
            std::cout << std::endl;
            break;
        case 't': // getSumOfSubtrees *done*
            std::cout << "Item to get sum of subtrees: ";
            std::cin >> key;
            tree.BinaryTree::getSumOfSubtrees(tree.root, key);
            break;
        case 'q': // quit *done*
            std::cout << "Quitting program..." << std::endl;
            return;
        default:
            std::cout << "Command not recognized. Try again" << std::endl;
            break;    
        }
    }

} // stringTree options


int main (int argc, char *argv[]) {

    BinaryTree<int> iTree = BinaryTree<int>();
    BinaryTree<float> fTree = BinaryTree<float>();
    BinaryTree<std::string> sTree = BinaryTree<std::string>();

    if (argc != 2) {
        std::cout << "Usage: ./main [inputfile.txt]" << std::endl;
        return 1;
    }

    if (strcmp(argv[1], "int-input1.txt") == 0) {
        iTree = createIntTree("int-input1.txt");
    } else if (strcmp(argv[1], "float-input1.txt") == 0) {
        fTree = createFloatTree("float-input1.txt");
    } else if (strcmp(argv[1], "string-input1.txt") == 0) {
        sTree = createStringTree("string-input1.txt");
    } else {
        std::cout << "Please enter int-input.txt || int-input2.txt || float-input.txt || string-input.txt"
        << std::endl;
    }

    std::string type;
    while(1) {
        printGreeting();
        std::cin >> type;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        printOptions();
        if (type == "i") {
            intTree(iTree);
            break;
        } else if (type == "f") {
            floatTree(fTree);
            break;
        } else if (type == "s") {
            stringTree(sTree);
            break;
        } else {
            std::cout << "Please enter a valid tree type" << std::endl;
            continue;
        }
        break;
    }
    return 0;
} // main