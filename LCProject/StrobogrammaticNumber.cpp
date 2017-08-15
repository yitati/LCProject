/******************************************************************************/
/*
* Question: #246 Strobogrammatic Number
* company tag: Facebook, Google
* A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
* Write a function to determine if a number is strobogrammatic. The number is represented as a string.
* For example, the numbers "69", "88", and "818" are all strobogrammatic.
*/
/*****************************************************************************/

#include <string>
#include <unordered_set>

using namespace std;

/*
 * the strobogrammatic number will consider "01869"
 */
bool isStrobogrammatic(string num)
{
	string stro = "01869";
	unordered_set<char> dict;
	for(char c : stro) dict.insert(c);
	int lhs = 0, rhs = num.size()-1;
	while(lhs <= rhs)
	{
		if(!dict.count(num[lhs]) || !dict.count(num[rhs])) return false;
		if(num[lhs] == '0' || num[lhs] == '1' || num[lhs] == '8')
		{
			if(num[rhs] != num[lhs]) return false;
		}
		else if(num[lhs] == '6')
		{
			if(num[rhs] != '9') return false;
		}
		else if(num[lhs] == '9')
		{
			if(num[rhs] != '6') return false;
		}
		lhs++;
		rhs--;
	}
	return true;
}


