/*
 * TotalHammingDistance.cpp
 *
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Now your job is to find the total Hamming distance between all pairs of the given numbers.
 */


/*
 * there are 32 bits in one int number, for one bit we count how many set bit, for example, if it is k, then there
 * will be (n-k) clear bits, so in this bit the hamming distance would be k*(n-k)
 * calculate for all 32 bits and we get our result
 */
int totalHammingDist(vector<int> nums)
{
	int total = 0;
	for(int i=0; i<32; i++)
	{
		int count0 = 0, count1 = 0;
		for(int num : nums)
		{
			int mask = 1 << i;
			if((num & mask) == mask) count1++;
			else count0++;
		}
		total += count1 * count0;
	}
	return total;
}


/*
 * Brutal force way
 */
int getHamming(int x, int y)
{
	int result = x^y, count = 0;
	while(result)
	{
		result &= (result-1);
		count++;
	}
	return count;
}

int totalHamming(vector<int> nums)
{
	int dist = 0;
	for(int i=0; i<nums.size()-1; i++)
	{
		for(int j=i+1; j<nums.size(); j++)
		{
			dist += getHamming(nums[i], nums[j]);
		}
	}
	return dist;
}



