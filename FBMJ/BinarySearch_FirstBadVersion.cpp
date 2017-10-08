/*
 * BinarySearch_FirstBadVersion.cpp
 *
 */


// Forward declaration of isBadVersion API.
bool isBadVersion(int version) { return true; };

// binary search 0 0 0 0 0 1 1 1 1 1 1 will find the first 1
int firstBadVersion(int n)
{
	int lhs = 1, rhs = n;
	// we want to have at least two neighboring versions left
	while (lhs + 1 < rhs)
	{
		int mid = lhs + (rhs - lhs) / 2;
		bool bad = isBadVersion(mid);
		if (bad)
		{
			rhs = mid;
		}
		else
		{
			lhs = mid;
		}
	}

	if (isBadVersion(lhs)) return lhs;
	else if (isBadVersion(rhs)) return rhs;
	return 0;
}

int firstBadVersion_update(int n)
{
	int lhs = 1, rhs = n;
	while(lhs < rhs)
	{
		int mid = lhs + (rhs - lhs)/2;
		bool bad = isBadVersion(mid);
		if(bad) rhs = mid;
		else lhs = mid+1;
	}
	return lhs;
}
