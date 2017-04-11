/******************************************************************************/
/*
* Question: #179 Largest Number
* Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
* Note: The result may be very large, so you need to return a string instead of an integer.
*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largestNumber(vector<int>& nums) 
{
	vector<string> collection;
	for (int num : nums)
	{
		collection.push_back(to_string(num));
	}
	sort(collection.begin(), collection.end(), [](const string & lhs, const string & rhs)->bool {return lhs + rhs > rhs + lhs; });

	string result;
	for (string str : collection)
	{
		result += str;
	}

	return result;
}
