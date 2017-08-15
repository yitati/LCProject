/************************************************************************************
 * Question #265 Paint House II
 * company tag: Facebook, LinkedIn
 * There are a row of n houses, each house can be painted with one of the k colors.
 * The cost of painting each house with a certain color is different. You have to paint all
 * the houses such that no two adjacent houses have the same color.
 * The cost of painting each house with a certain color is represented by a n x k cost matrix.
 * For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the
 * cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.
 * Note:
 * All costs are positive integers.
 * Follow up:
 * Could you solve it in O(nk) runtime?
 **********************************************************************************/

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/*
 * we can solve this problem with O(nk^2) time, then how to optimize it with O(nk)?
 * there are max of two possible values for each row - the min cost and the second min cost
 * so in each layer we need to keep such information - minCost, secMin and minIdx
 * then in the next layer if index != minIndex we can add with minCost, otherwise
 * add with secMin
 */
int minCostII(vector<vector<int>>& costs)
{
    if(costs.empty() || costs[0].empty()) return 0;
    int lastMin = costs[0][0], lastSec = costs[0][0], lastIdx = 0;
    int n = costs.size(), k = costs[0].size();
    // start accumulating the cost sum
    for(int i=0; i<n; i++)
    {
        int minCost=-1, secMin=-1, minIdx;
        for(int j=0; j<k; j++)
        {
            if(i > 0)
            {
                if(j != lastIdx) costs[i][j] += lastMin;
                else costs[i][j] += lastSec;
            }
            // find the min and second min
            if(minCost == -1 || costs[i][j] < minCost)
            {
                secMin = minCost;
                minIdx = j;
                minCost = costs[i][j];
            }
            else if(secMin == -1 || costs[i][j] < secMin)
            {
                secMin = costs[i][j];
            }
        }
        lastMin = minCost;
        lastSec = secMin;
        lastIdx = minIdx;
    }
    lastMin = costs[n-1][0];
    for(int j=0; j<k; j++)
    {
        lastMin = min(lastMin, costs[n-1][j]);
    }

    return lastMin;
}

/*
 * a improved solution is to save index instead of the values for each elements
 */

