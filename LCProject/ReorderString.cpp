/*
Given an array of elements, reorder it as follow:

{ N1, N2, N3, …, N2k } → { N1, Nk+1, N2, Nk+2, N3, Nk+3, … , Nk, N2k }

{ N1, N2, N3, …, N2k+1 } → { N1, Nk+1, N2, Nk+2, N3, Nk+3, … , Nk, N2k, N2k+1 }

Try to do it in place.

Assumptions

The given array is not null
Examples

{ 1, 2, 3, 4, 5, 6} → { 1, 4, 2, 5, 3, 6 }

{ 1, 2, 3, 4, 5, 6, 7, 8 } → { 1, 5, 2, 6, 3, 7, 4, 8 }

{ 1, 2, 3, 4, 5, 6, 7 } → { 1, 4, 2, 5, 3, 6, 7 }
*/

#include <vector>
#include <algorithm>

using namespace std;

// for even number we reorder the whole array
// for odd number we leave the last one out

void reorderArray(vector<int> & input, int lhs, int rhs)
{
	// base case
	if (rhs - lhs <= 1) return;
	int size = rhs - lhs + 1;
	int mid = lhs + size / 2;
	int leftmid = lhs + size / 4;
	int rightmid = lhs + size * 3 / 4;

	// first reverse [leftmid, rightmid)
	reverse(input.begin() + leftmid, input.begin() + rightmid);
	reverse(input.begin() + leftmid, input.begin() + mid); // reverse [leftmid, mid)
	reverse(input.begin() + mid, input.begin() + rightmid); // reverse [mid, rightmid)

	reorderArray(input, lhs, 2 * (leftmid - lhs) + lhs - 1);
	reorderArray(input, 2 * (leftmid - lhs) + lhs, rhs);
}

vector<int> reorder(vector<int> array)
{
	if (array.size() <= 2) return array;
	int size = array.size();
	if (size % 2 == 0)  reorderArray(array, 0, size - 1);
	else  reorderArray(array, 0, size - 2);
	return array;
}

/*
Time complexity: O(NlogN)
*/

