
#include <vector>

using namespace std;

/*
 * Best time to buy and sell stocks with at most one transaction
 * We want to buy the stock at the lowest point and sell it out at the hightest one after it.
 * So in each point we calculate the maximum profit when buying stock before this day, and also
 * update min price for the later transaction.
 */
int bestTimeToBuySellStockI(vector<int>& prices)
{
	if(prices.size() < 2) return 0;
	int profit = 0, buy = prices[0];
	for(int i=1; i<prices.size(); i++)
	{
		profit = max(profit, prices[i]-buy);
		buy = min(buy, prices[i]);
	}

	return profit;
}

/*
 * Best time to buy and sell stocks with two transactions only
 * Basically we want to stat the max profit when transaction happens before day i (inclusive) and the one after day i (exclusive).
 */
int bestTimeToBuySellStockIII(vector<int>& prices)
{
	if(prices.size() < 2) return 0;
	int n = prices.size(), maxProfit = 0, res = 0;
	int buy = prices[0], sell = prices[n-1];
	vector<int> profit(n, 0);

	// calculate the max profit when transaction happens before or at day i
	for(int i = 1; i < n; i++)
	{
		maxProfit = max(maxProfit, prices[i] - buy);
		profit[i] = maxProfit;
		buy = min(prices[i], buy);
		res = max(res, maxProfit);           // pitfall here: if we have only two elements in the array
	}
	maxProfit = 0;
	// calculate the max profit when trasaction happens after day i (exclusive)
	for(int i = n-2; i > 0; i--)
	{
		maxProfit = max(maxProfit, sell-prices[i]);
		profit[i-1] += maxProfit;
		res = max(res, profit[i-1]);
		sell = max(sell, prices[i]);
	}

	return res;
}



