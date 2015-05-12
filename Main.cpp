// CS110C Lab 5 12/11/13
// Group : Lucas Hom, Felix Chan Lee, Alan Chan
// Purpose: To create a binary tree as described and to translate morse code of -  and . back into characters 

#include <iostream>
#include "MasterTree.h"
using namespace std;

int main()
{
	MasterTree mtree; // initialize the master tree
	cout << "translation is " << endl;
	cout << mtree.translate("-") << mtree.translate(".-.") << mtree.translate(".") << mtree.translate(".") << mtree.translate("...") << " ";
	cout << mtree.translate("-.-.") << mtree.translate(".-") << mtree.translate("-.") << " ";
	cout << mtree.translate("-...") << mtree.translate(".") << " ";
	cout << mtree.translate("..-.") << mtree.translate("..-") << mtree.translate("-.") << " ";
	cout << mtree.translate("..---") << mtree.translate("-----") << mtree.translate("-----") << mtree.translate("--...") << " " << endl;
	return 0;
}

