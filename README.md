# Binary_Tree

Author: Katarzyna Miałkowska

## Contents ##
1) generator.cxx
- Generate random output by accepting in argument
[number of draws] [maximum range]

2) BinaryTree.hxx
- Contains BST implementations and its main methods
 
3) BinaryTree.cxx
 - The program builds a binary tree and displays it graphically.

4) TreeIteration.cxx
- The program builds a binary tree and prints it (iterative preorder) and displays it graphically.
 
5) TestBinaryTree.cxx and TestBinaryTree.hxx
- Checks if a structure is a BST and tests it.

## Makefile ##
-To compile all programs, execute:
 make all
- To clean the contents of unnecessary files, execute:
 make clean
- To run BinaryTree.cxx execute:
make binarytree
- To run TreeIteration.cxx execute:
make treeiteration
- To run the tester, execute:
make test

## Tester ##
- TestBinaryTree.cxx and TestBinaryTree.hxx.

- The program creates a small BST tree, displays it graphically in the terminal and displays its properties.
- The program creates a BST for 100,000 data and checks if its structure is correct.
- The program compares tree display time, number lookup, recursively and iteratively. 
