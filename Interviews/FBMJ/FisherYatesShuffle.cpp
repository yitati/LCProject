/*
 * MianJing: Fisher Yates Shuffle
 * company tag: Facebook
 * Also called the Knuth Fisher Yates Shuffle.
 * Ramdomly pick one element in the array and swap it with the end of the element.
 * Then pick up another and swap with the one next to the last ...
 * Follow-up:
 * company tag: Facebook
 * How to shuffle a weighted array?
 */

#include <vector>
#include <algorithm>

using namespace std;

// this is a mordern way of shuffling
// time complexity is O(n)
void FisherYatesShuffle(vector<int>& input)
{
	for(int i=input.size()-1; i > 0; i--)
	{
		int r = rand()%(i+1);  // randomly choose a number that is in "unshuffled" pack
		swap(input[r], input[i]);
	}
}



