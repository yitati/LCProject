/*
 * FruitList.cpp
 *
 *  Created on: Sep 23, 2017
 *      Author: JoanneY1
 */

#include <vector>

using namespace std;

bool checkList(vector<vector<string>> codeList, vector<string>& shoppingList)
{
	int sidx = 0, r = 0;
	while(sidx + codeList[r].size() <= shoppingList.size() && r < codeList.size())
	{
		int i;
		for(i=0; i < codeList[r].size(); i++)
		{
			if(shoppingList[sidx + i] != codeList[r][i] && codeList[r][i] != "anything")  break;
		}
		if(i == codeList[r].size())
		{
			sidx += i;
			r++;
		}
		else
		{
			sidx++;
		}
	}
	if(sidx == shoppingList.size() && r == codeList.size()) return true;
	return false;
}





