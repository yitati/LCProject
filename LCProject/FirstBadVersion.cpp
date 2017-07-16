/******************************************************************************
* Question: #278 First Bad Version
* company tag: Facebook
* You are a product manager and currently leading a team to develop a new product. Unfortunately, 
* the latest version of your product fails the quality check. Since each version is developed based 
* on the previous version, all the versions after a bad version are also bad. 
* Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes 
* all the following ones to be bad. 
* You are given an API bool isBadVersion(version) which will return whether version is bad. 
* Implement a function to find the first bad version. You should minimize the number of calls to the API.
*****************************************************************************/

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
