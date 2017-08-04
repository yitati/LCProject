/*
 * Laicode_SortInSpecificOrder.cpp
Given two integer arrays A1 and A2, sort A1 in such a way that the relative order among the elements will be same as those are in A2.

For the elements that are not in A2, append them in the right end of the A1 in an ascending order.

Assumptions:

A1 and A2 are both not null.
There are no duplicate elements in A2.
Examples:

A1 = {2, 1, 2, 5, 7, 1, 9, 3}, A2 = {2, 1, 3}, A1 is sorted to {2, 2, 1, 1, 3, 5, 7, 9}
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// solution 1 - use lambda function to customize the sort
// Time complexity is maximum O(nlgn)
vector<int> sortSpecial_lambda(vector<int> A1, vector<int> A2)
{
  unordered_map<int, int> numMap;
  for(int i=0; i<A2.size(); i++){
    numMap[A2[i]] = i;
  }
  int slow = 0, fast = 0;
  while(fast < A1.size()){
    if(numMap.count(A1[fast])) swap(A1[slow++], A1[fast++]);
    else fast++;
  }
  sort(A1.begin(), A1.begin()+slow, [&](const int& num1, const int& num2){
    return numMap[num1] < numMap[num2];
  });
  sort(A1.begin()+slow, A1.end());
  return A1;
}


vector<int> sortSpecial_comparator(vector<int> A1, vector<int> A2)
{
	  unordered_map<int, int> numMap;
	  for(int i=0; i<A2.size(); i++){
	    numMap[A2[i]] = i;
	  }
	  // BAOBAO TODO :  how to implement this special comparator?
}


//solution 2 - keep rainbowl sorting
// Time complexity is O(mn)
int moveToFront(vector<int>& A1, int lhs, int key)
{
	if(lhs >= A1.size()) return lhs;
	int lower = lhs, upper = A1.size()-1;
	while(lower <= upper){
		if(A1[lower] == key) lower++;
		else if(A1[upper] != key) upper--;
		else swap(A1[lower++], A1[upper--]);
	}
	return lower;
}

vector<int> sortSpecial_rainbow(vector<int> A1, vector<int> A2)
{
	int lhs = 0;
	for(int v : A2){
		lhs = moveToFront(A1, lhs, v);
		if(lhs > A1.size()) break;
	}
	if(lhs < A1.size()){
		sort(A1.begin()+lhs, A1.end());
	}
	return A1;
}


/*
int main(int argc, char ** argv)
{
	vector<int> A1 = {2, 1, 2, 5, 7, 1, 9, 3};
	vector<int> A2 = {2, 1, 3};
	vector<int> result = sortSpecial_lambda(A1, A2);
	int i = 0;
	while(i < result.size()){
		cout << result[i++] << "    ";
	}
	cout << endl;
	system("pause");
}
*/



