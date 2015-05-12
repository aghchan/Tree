// Header file TreeException.h for the ADT binary tree.
// Written by:     Steve Abensohn
// Date:           5/30/02
// Modified:       1/6/12
// ********************************************************
#include <stdexcept>
#include <string>
using namespace std;

// in case of error, this exception is thrown
class TreeLogicException : public logic_error 
{
	public:
		TreeLogicException(const string & Message = "") :
			logic_error(Message.c_str())
		{ } // end constructor
}; // end TreelogicException