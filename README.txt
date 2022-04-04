Jacob Reiser
810 687 011
jpreiser@uga.edu
Data Structures Assignment 4: BinaryTree

To compile the code, type 'make' into the command line.

To run, type './main <input file>' into the command line.

To clean the directory, type 'make clean' into the command line.

Currently this prgram runs with int-input1.txt, float-input1.txt,
and string-input1.txt. To modify the lists, either edit these files
directly, repalce them with a file of the same name, or manipulate them
within the program.

The pseudo code for singParent is
    if passed node is null
       return 0
    if either the left or right children of the node contain a value and the
    other contains a child,
       return a recursive call of left + a recursive call of right + 1
    else
        return a recursive call of the leftchild  + a recursive call of the right child

This method has a base case of constant time, O(1), + at most N-1 if the nodes are entered in order,
giving it a complexity of O(1 + (n-1)) or just O(N) if all numbers are entered in order. If they are
not entered in order, then the compexity would be O(N) if it had to search the entire tree and there
were no single parent nodes.

The pseudo code for getNumLeafNodes is
if node is null
   return 0 as the base case
else if both left and right nodes are NULL
     return 1
else
    return a recursive call of node->left + node->right

This code also has a complexity of O(n), since the entire tree needs to be searched
in the worst case. In most cases, it will still have a compelxtiy of 1 for the base case
+ (n-1) to search the farthest node down, resulting in O(N).

The psuedo code for getSumOfSubtrees would be O(N) in the worst case, if the input is the
greatest value in the tree, whose children would have a sum of 0 since there would be no children.
It has a complexity of 1 for the base case + n-1 to reach the final node for O(1 + (n-1)) or
O(N) according to the master theorem.
