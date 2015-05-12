#include "BinaryTree.h"      // header file
#include <cstddef>  // definition of NULL
#include <iostream>
using namespace std;

BinaryTree::BinaryTree()
{
	leftSubtreePtr = rightSubtreePtr = NULL;
	pItem = NULL;
}

BinaryTree::BinaryTree(const TreeItemType& rootItem)
{
	pItem = new TreeItemType(rootItem);
	leftSubtreePtr = rightSubtreePtr = NULL;
}

BinaryTree::BinaryTree(const TreeItemType& rootItem,
	BinaryTree& leftTree,
	BinaryTree& rightTree)
{
	pItem = new TreeItemType(rootItem);
	leftSubtreePtr = rightSubtreePtr = NULL;

	attachLeftSubtree(leftTree);
	attachRightSubtree(rightTree);
}

BinaryTree::BinaryTree(const BinaryTree& tree)
{
	copyTree(tree);
}

BinaryTree::~BinaryTree()
{
	destroyTree();
}

bool BinaryTree::isEmpty() const
{
	return bool(pItem == NULL);
}

TreeItemType BinaryTree::getRootData() const
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	return *pItem;
}

void BinaryTree::setRootData(const TreeItemType& newItem)
{
	if (pItem != NULL)
		*pItem = newItem;
	else
		pItem = new TreeItemType(newItem);

}

void BinaryTree::attachLeft(const TreeItemType& newItem)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else if (leftSubtreePtr != NULL)
		throw TreeLogicException(
		"TreeLogicException: Cannot overwrite left subtree");
	else  // nonempty tree; no left child
		leftSubtreePtr = new BinaryTree(newItem);
}

void BinaryTree::attachRight(const TreeItemType& newItem)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else if (rightSubtreePtr != NULL)
		throw TreeLogicException(
		"TreeLogicException: Cannot overwrite right subtree");
	else  // nonempty tree; no right child
		rightSubtreePtr = new BinaryTree(newItem);
}

void BinaryTree::attachLeftSubtree(BinaryTree& leftTree)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else if (leftSubtreePtr != NULL)
		throw TreeLogicException(
		"TreeLogicException: Cannot overwrite left subtree");
	else  // nonempty tree; no left child
	{
		leftSubtreePtr = new BinaryTree(leftTree);
		leftTree.destroyTree();
	}
}

void BinaryTree::attachRightSubtree(BinaryTree& rightTree)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else if (rightSubtreePtr != NULL)
		throw TreeLogicException(
		"TreeLogicException: Cannot overwrite right subtree");
	else  // nonempty tree; no right child
	{
		rightSubtreePtr = new BinaryTree(rightTree);
		rightTree.destroyTree();
	}
}

void BinaryTree::detachLeftSubtree(BinaryTree& leftTree)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else
	{
		leftTree = *leftSubtreePtr;
		leftSubtreePtr = NULL;
	}
}

void BinaryTree::detachRightSubtree(BinaryTree& rightTree)
throw(TreeLogicException)
{
	if (isEmpty())
		throw TreeLogicException(
		"TreeLogicException: Empty tree");
	else
	{
		rightTree = *rightSubtreePtr;
		rightSubtreePtr = NULL;
	}
}


BinaryTree& BinaryTree::getLeftSubtree()
throw(TreeLogicException)
{
	if (isEmpty())
	{
		throw TreeLogicException(
			"TreeLogicException: Empty tree");

		// unreached code to satisfy Visual C++ return requirement
		BinaryTree* emptyTree = new BinaryTree();

		return *emptyTree;
	}

	else if (leftSubtreePtr)
	{
		return *leftSubtreePtr;
	}
	else
	{
		BinaryTree* emptyTree = new BinaryTree();

		return *emptyTree;
	}
}

BinaryTree& BinaryTree::getRightSubtree()
throw(TreeLogicException)
{
	if (isEmpty())
	{
		throw TreeLogicException(
			"TreeLogicException: Empty tree");

		// unreached code to satisfy Visual C++ return requirement
		BinaryTree* emptyTree = new BinaryTree();

		return *emptyTree;
	}
	else if (rightSubtreePtr)
	{
		return *rightSubtreePtr;
	}
	else
	{
		BinaryTree* emptyTree = new BinaryTree();
		return *emptyTree;
	}
}

void BinaryTree::preorderTraverse(FunctionType visit)
{
	if (pItem != NULL)
	{
		visit(*pItem);
		if (leftSubtreePtr)
			leftSubtreePtr->preorderTraverse(visit);
		if (rightSubtreePtr)
			rightSubtreePtr->preorderTraverse(visit);
	}
}

void BinaryTree::inorderTraverse(FunctionType visit)
{
	if (pItem != NULL)
	{
		if (leftSubtreePtr)
			leftSubtreePtr->inorderTraverse(visit);
		visit(*pItem);
		if (rightSubtreePtr)
			rightSubtreePtr->inorderTraverse(visit);
	}
}

void BinaryTree::postorderTraverse(FunctionType visit)
{
	if (pItem != NULL)
	{
		if (leftSubtreePtr)
			leftSubtreePtr->postorderTraverse(visit);
		if (rightSubtreePtr)
			rightSubtreePtr->postorderTraverse(visit);
		visit(*pItem);
	}
}

BinaryTree& BinaryTree::operator=(const BinaryTree& rhs)
{
	if (this != &rhs)
	{
		//           destroyTree();  // deallocate left-hand side
		copyTree(rhs);  // copy right-hand side
	}

	return *this;
}

void BinaryTree::copyTree(const BinaryTree& tree)
{
	// preorder traversal
	if (tree.pItem)
	{      // copy node
		TreeItemType Temp = *(tree.pItem);
		pItem = new TreeItemType(Temp);

		if (tree.leftSubtreePtr)
		{
			leftSubtreePtr =
				new BinaryTree(*(tree.leftSubtreePtr));
		}
		else
		{
			leftSubtreePtr = NULL;
		}

		if (tree.rightSubtreePtr)
		{
			rightSubtreePtr =
				new BinaryTree(*(tree.rightSubtreePtr));
		}
		else
		{
			rightSubtreePtr = NULL;
		}
	}
	else
	{
		pItem = NULL;  // copy empty tree
		leftSubtreePtr = rightSubtreePtr = NULL;
	}
}

void BinaryTree::destroyTree()
{
	// postorder traversal

	if (leftSubtreePtr)
	{
		leftSubtreePtr->destroyTree();
		delete leftSubtreePtr;
		leftSubtreePtr = NULL;
	}

	if (rightSubtreePtr)
	{
		rightSubtreePtr->destroyTree();
		delete rightSubtreePtr;
		rightSubtreePtr = NULL;
	}

	if (pItem)
	{
		delete pItem;
		pItem = NULL;
	}
}
