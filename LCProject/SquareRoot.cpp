/*
 * Question: #69 Sqrt(x)
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 */
/*****************************************************************************/


// This is the Newton
int mySqrt(int x)
{
    long r = x;
    while(r*r > x)
    {
        r = (r + x/r)/2;
    }
    return r;
}

int mySqrt_bin(int x)
{
    int lhs = 1, rhs = x;
    while(lhs < rhs)
    {
        int mid = lhs + (rhs - lhs)/2;
        if(mid * mid == x) return mid;
        else if(mid * mid > x) rhs = mid-1;
        else{
            if((mid+1) * (mid+1) > x) return mid;
            else lhs = mid+1;
        }
    }
    return -1;
}
