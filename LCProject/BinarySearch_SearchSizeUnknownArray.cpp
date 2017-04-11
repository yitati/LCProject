/*
Given a integer dictionary a of unknown size, where the numbers in the dictionary are sorted in ascending order,
determine if a given target inteer T is in the dictionary. Return the index of T in A, return -1 if T is not in A.
*/

#include <iostream>
#include <vector>

using namespace std;

class UnknownSizeVector {
public:
	int get(int index)
	{
		return arr[index];
	}

	vector<int>arr;
};

// set lower and upper, move upper to 2*lower until upper > target
int searchUnknownSizeArray(UnknownSizeVector input, int target)
{
	if (target < input.get(0)) return -1;
	if (target == input.get(0)) return 0;
	int lower = 1, upper = lower;
	while (input.get(upper) <= target)
	{
		if (input.get(upper) == target) return upper;
		lower = upper;
		upper = 2 * lower;
	}
	// then serach between lower and upper
	while (lower <= upper)
	{
		int mid = lower + (upper - lower) / 2;
		if (target == input.get(mid)) return mid;
		else if (target < input.get(mid)) upper = mid - 1;
		else lower = mid + 1;
	}
	return -1;
}

/*
int main(int argc, char ** argv)
{
	int n = 5000;
	UnknownSizeVector nums;
	for (int i = 0; i < n; i++)
	{
		nums.arr.push_back(i * 2);
	}

	cout << searchUnknownSizeArray(nums, 0) << endl;
	cout << searchUnknownSizeArray(nums, 13) << endl;
	cout << searchUnknownSizeArray(nums, 66) << endl;

	system("pause");

}

*/