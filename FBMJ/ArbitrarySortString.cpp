/*
 * CustomizeSortAlphabet.cpp
Sort an input string using an arbitrary alphabet
For example: custom alphabet: xyzabc.
input to sort according to custom alphabet: cyxz
output according to custom alphabet: xyzc
 */

#include <string>
#include <unordered_map>

using namespace std;

// use comparator and sort it
string arbitraryAlphaSort(string input, string cusAlpha)
{
	unordered_map<char, int> order;
	string result;
	int idx = 0;
	for(char c : cusAlpha) order[c] = idx++;

	// need to handle the situation that some char does not exit in the alphabet
	sort(input.begin(), input.end(), [&](const char& lhs, const char& rhs)->bool{
		if(order.count(lhs) && order.count(rhs)) return order[lhs] < order[rhs];
		else if(!order.count(lhs) && !order.count(rhs)) return lhs < rhs;
		else if(!order.count(lhs)) return false;
		else return true;
	});

	return input;
}


string arbitraryAlpha(string input, string cusAlpha)
{
	unordered_map<char, int> order;
	string result;
	int idx = 0;
	for(char c : cusAlpha) order[c] = idx++;

	auto comp = [&](const char& lhs, const char& rhs)->bool{
		return order[lhs] > order[rhs];
	};

	priority_queue<char, vector<char>, decltype(comp)> minHeap(comp);

	for(char c : cusAlpha)
	{
		minHeap.push(c);
	}

	while(!minHeap.empty())
	{
		result.push_back(minHeap.top());
		minHeap.pop();
	}

	return result;
}




