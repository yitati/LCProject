// Selection sort an array a[] with size n.
// time complexity is O(n^2)

#include <iostream>
#include <vector>

using namespace std;

void SelectionSort(int a[], int n)
{
	int global, temp;
	for(int i=0; i < n-1; i++){
		// outer loop: how many iterations
		global = i;
		for(int j=i+1; j<n; j++){
			// innner loop: find the global min from the rest elements.
			if (a[j] < a[global]) {
				// record the index of the smallest element.
				global = j;
			}
		}
		// swap the global (a[index]) min with a[j].
		temp = a[i];
		a[i] = a[global];
		a[global] = temp;
	}
}

// selection sort will alwasy find the min from the rest of the array and insert in the first place
// iterative way
void SelectionSort_iteration(vector<int> & input)
{
	int global = 0;
	for (int i = 0; i < input.size()-1; i++)
	{
		global = i;
		for (int j = i + 1; j < input.size(); j++)
		{
			// mark the min index
			if (input[global] > input[j]) global = j;
		}
		swap(input[i], input[global]);
	}
}


/*
int main(int argc, char ** argv)
{
	int input[] = { 3, 6, 2, 8, 3, 5, 9, 0, 1 };

	vector<int> arr(input, input + sizeof(input) / sizeof(int));

	SelectionSort_iteration(arr);
	
	for (int i = 0; i < 9; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;

	system("pause");
}
*/
