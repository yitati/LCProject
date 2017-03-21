/******************************************************************************/
/*
* Question: #385 Mini Parser
* Given a nested list of integers represented as a string, implement a parser to deserialize it.
* Each element is either an integer, or a list -- whose elements may also be integers or other lists.
* Note: You may assume that the string is well-formed: 
* String is non-empty.
* String does not contain white spaces.
* String contains only digits 0-9, [, - ,, ].

*/
/*****************************************************************************/

#include <vector>

using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	// Constructor initializes an empty nested list.
     NestedInteger();

     // Constructor initializes a single integer.
     NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
 };


NestedInteger deserialize(string s) 
{

}

