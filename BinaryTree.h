// ********************************************************
// Header file BinaryTree.h for the ADT binary tree.
// Written by:     Steve Abensohn
// Date:           5/30/02
// Modified from:  Binary Tree, Chapter 10
//                 Data Abstraction and Problem Solving with C++
//                 Walls and Mirrors, 3rd edition
//                 Carrano and Prichard
//                 Pearson Education
//                 Copyright 2002
// ********************************************************

#include "TreeException.h"

typedef int TreeItemType;

typedef void(*FunctionType)(TreeItemType& anItem);

class BinaryTree
{
public:
	// constructors and destructor:
	BinaryTree(); //default constructor
	BinaryTree(const TreeItemType& rootItem); //constructor with root
	BinaryTree(const TreeItemType& rootItem, 
		BinaryTree& leftTree,
		BinaryTree& rightTree); //constructor with root, left subtree, and right subtree
	BinaryTree(const BinaryTree& tree); // constructor with binary tree
	virtual ~BinaryTree(); // tree destructor

	// binary tree operations:
	virtual bool isEmpty() const; // checks if empty

	virtual TreeItemType getRootData() const // retrieves root value of the tree
		throw(TreeLogicException);

	virtual void setRootData(const TreeItemType& newItem); // sets root value of tree

	virtual void attachLeft(const TreeItemType& newItem) //attaches new item to left
		throw(TreeLogicException);

	virtual void attachRight(const TreeItemType& newItem) // attaches new item to right
		throw(TreeLogicException);

	virtual void attachLeftSubtree(BinaryTree& leftTree) // attaches left subtree
		throw(TreeLogicException);

	virtual void attachRightSubtree(BinaryTree& rightTree) // attaches right subtree
		throw(TreeLogicException);

	virtual void detachLeftSubtree(BinaryTree& leftTree) // detahes left subtree
		throw(TreeLogicException);

	virtual void detachRightSubtree(BinaryTree& rightTree) // detaches right subtree
		throw(TreeLogicException);

	virtual BinaryTree& getLeftSubtree() // gets address of left subtree
		throw(TreeLogicException);

	virtual BinaryTree& getRightSubtree() // gets address of right subtree
		throw(TreeLogicException);

	virtual BinaryTree& operator=(const BinaryTree& rhs); // redefines = operator

	virtual void preorderTraverse(FunctionType visit); 
	virtual void inorderTraverse(FunctionType visit);
	virtual void postorderTraverse(FunctionType visit);

protected:
	void copyTree(const BinaryTree& tree); // function copies tree
	void destroyTree(); // function destroys tree

private:
	BinaryTree* leftSubtreePtr; // point to left subtree
	BinaryTree* rightSubtreePtr; // pointer to right subtree
	TreeItemType* pItem;      // pointer to root item
};
