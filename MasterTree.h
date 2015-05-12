#include "BinaryTree.h"

class MasterTree
{
	public:
		MasterTree(); // default constructor for master tree
		char translate(string); // interprets morse code into characters with the master tree
	private:
		BinaryTree mtree; // creates master tree
};