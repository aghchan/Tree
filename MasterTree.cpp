#include "MasterTree.h"
#include <iostream>

// purpose: constructor for tree
// @param: none
// @post: the master tree is initialized
MasterTree::MasterTree()
{
	// sets up tree as described
	BinaryTree tree1('5');
	BinaryTree tree2('4');
	BinaryTree tree3(' ');
	BinaryTree tree4('3');
	BinaryTree tree5('6');
	BinaryTree tree6(' ');
	BinaryTree tree7('7');
	BinaryTree tree8(' ');
	BinaryTree tree9('8');
	BinaryTree tree10(' ');
	BinaryTree tree11('9');
	BinaryTree tree12('0');
	BinaryTree tree13('H', tree1, tree2);
	BinaryTree tree14('V', tree3, tree4);
	BinaryTree tree15('F');
	BinaryTree tree46(' ');
	BinaryTree tree47('2');
	BinaryTree tree16(' ', tree46, tree47);
	BinaryTree tree17('L');
	BinaryTree tree18('P');
	BinaryTree tree19('1');
	BinaryTree tree20(' ');
	BinaryTree tree21('J', tree20, tree19);
	BinaryTree tree22('B', tree5, tree6);
	BinaryTree tree23('X');
	BinaryTree tree24('C');
	BinaryTree tree25('Y');
	BinaryTree tree26('Z', tree7, tree8);
	BinaryTree tree27('Q');
	BinaryTree tree28(' ', tree9, tree10);
	BinaryTree tree29(' ', tree11, tree12);
	BinaryTree tree30('S', tree13, tree14);
	BinaryTree tree31('U', tree15, tree16);
	BinaryTree tree32(' ');
	BinaryTree tree33('R', tree17, tree32);
	BinaryTree tree34('W', tree18, tree21);
	BinaryTree tree35('D', tree22, tree23);
	BinaryTree tree36('K', tree24, tree25);
	BinaryTree tree37('G', tree26, tree27);
	BinaryTree tree38('O', tree28, tree29);
	BinaryTree tree39('I', tree30, tree31);
	BinaryTree tree40('A', tree33, tree34);
	BinaryTree tree41('N', tree35, tree36);
	BinaryTree tree42('M', tree37, tree38);
	BinaryTree tree43('E', tree39, tree40);
	BinaryTree tree44('T', tree41, tree42);
	BinaryTree tree45(' ', tree43, tree44);
	mtree = tree45; //set ptr private variable to the root



}

// purpose: interprets input of . or - 
// @param  string of morse code
// @pre the morse code is a string in the form of . and -
// @post using master tree converts the . and - to appropriate characters
char MasterTree::translate(string uncoded)
{
	BinaryTree* temp; //temp ptr
	temp = &mtree; // point to the master tree root

	char translation; // initializing variable

	for (int i = 0; i < uncoded.length(); i++) 
	{
		if (uncoded[i] == '.') // for case of input of . to get left subtree
		{
			temp = &temp->getLeftSubtree();
		}
		else // other case of - to get right subtree
		{
			temp = &temp->getRightSubtree();
		}
	}

	translation = temp->getRootData(); // retrieve value of the final temp pointer
	temp = &mtree; //Reset to point to root

	return translation; // returns value

}
