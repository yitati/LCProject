/*
 * FBMJ_BuyCakes.cpp
 *
Suppose there are three kinds of boxes of cakes. One has 6 cakes, one has 9 cakes
and one has 20. You are given
a number, return if you can buy cakes.
 */

/*
 * this is a dp problem, if we use dp[i] to denote if we can buy i cakes
 * with above three kinds of cake boxes.
 * Then dp[i] = dp[j] && i-j == 6/9/20
 * Similar to LC322 Coin Change
 */


#include <iostream>
#include <vector>

using namespace std;

bool canBuyCakes1(int money)
{
	int start = 0;
	vector<bool> dp(money+1);
	dp[0] = true;
	for(int i=0; i<money; i++)
	{
		if(dp[i] == false) continue;
		if(i+6 <= money) dp[i+6] = true;
		if(i+9 <= money) dp[i+9] = true;
		if(i+20 <= money) dp[i+20] = true;
	}
	return dp[money];
}

bool canBuyCakes(int money)
{
	if(money == 0) return true;
	if(money < 0) return false;
	else{
		if(canBuyCakes(money-6) || canBuyCakes(money-9) || canBuyCakes(money-20)){
			return true;
		}
	}
	return false;
}

/*
int main(int argc, char ** argv)
{
	cout << canBuyCakes(1) << endl;
	cout << canBuyCakes(6) << endl;
	cout << canBuyCakes(26) << endl;
	cout << canBuyCakes(27) << endl;
}
*/



