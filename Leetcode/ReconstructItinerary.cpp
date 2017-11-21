/******************************************************************************/
/*
* Question: #332 Reconstruct Itinerary
* Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. 
* All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK. 

* Note:
* 1.If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when 
* read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
* 2.All airports are represented by three capital letters (IATA code).
* 3.You may assume all tickets form at least one valid itinerary.


Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].


Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order. 

*/
/*****************************************************************************/

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <map>

using namespace std;

bool findItinerary_dfs(unordered_map<string, map<string, int>> & itinerary, vector<string> & path, int ports)
{
	if (path.size() == ports)
	{
		return true;
	};

	string last = path.back();
	for (auto it = itinerary[last].begin(); it != itinerary[last].end(); it++)
	{
		if (it->second <= 0) continue;
		it->second--;
		path.push_back(it->first);
		if (findItinerary_dfs(itinerary, path, ports))
		{
			return true;
		}
		path.pop_back();
		it->second++;
	}
	return false;
}

vector<string> findItinerary(vector<pair<string, string>> tickets)
{
	if (tickets.empty()) return{};
	int ports = tickets.size() + 1;

	vector<string>path;
	path.push_back("JFK");
	unordered_map<string, map<string, int>> itinerary;
	for (pair<string, string> ticket : tickets)
	{
		itinerary[ticket.first][ticket.second]++;
	}
	// dfs find one solution, if we have n tickets then should be n+1 itinerary
	findItinerary_dfs(itinerary, path, ports);
	return path;
}