/******************************************************************************/
/*
* Question: #269 Alien Dictionary
* There is a new alien language which uses the latin alphabet. However, the order among letters
* are unknown to you. You receive a list of non-empty words from the dictionary, where words are
* sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
 Given the following words in dictionary,
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

The correct order is: "wertf".

Example 2:
 Given the following words in dictionary,
[
  "z",
  "x"
]

The correct order is: "zx".

Example 3:
 Given the following words in dictionary,
[
  "z",
  "x",
  "z"
]

The order is invalid, so return "".

* Note:
* 1.You may assume all letters are in lowercase.
* 2.You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
* 3.If the order is invalid, return an empty string.
* 4.There may be multiple valid order of letters, return any one of them is fine.
/*****************************************************************************/

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <stack>

using namespace std;

unordered_map<char, unordered_set<char>> graph;
typedef enum {
	NOT_VISITED = 0, VISITING, VISITED
} STATUS;


/**************************** Helper Function Start ****************************/
// true or false indicate if there is any cycle in the graph
bool fillOrder(stack<char>& topOrder, unordered_map<char, STATUS>& state, char curr)
{
	// set flag for current node
	state[curr] = VISITING;
	for (auto& neigh : graph[curr]) {
		if (state[neigh] == VISITED)
			continue;
		else if (state[neigh] == VISITING)
			return false; // find a node on path
		else {
			if (!fillOrder(topOrder, state, neigh))
				return false;
		}
	}
	state[curr] = VISITED;  // change state to VISITED only when all neighbors checked
	topOrder.push(curr);
	return true;
}
// add nodes to graph from two strings
void addGraphNodes(const string& word1, const string& word2) {
	int i = 0;
	for (char c : word2)
		graph[c];
	for (i = 0; i < word1.length() && i < word2.length(); i++) {
		if (word1[i] == word2[i])
			continue;
		else {
			graph[word1[i]].insert(word2[i]);
			break;
		}
	}
}
// build graph from string vector
void buildTopoGraph(vector<string>& words) {
	if (words.empty())
		return;
	for (char c : words[0])
		graph[c];
	for (int i = 0; i < words.size() - 1; i++) {
		addGraphNodes(words[i], words[i + 1]);
	}
}

/**************************** Helper Function End ****************************/
// actually a topological sort problem
string alienOrder(vector<string>& words)
{
	if (words.empty())
		return "";
	// build graph
	buildTopoGraph(words);
	// do topological sort
	int n = graph.size();
	unordered_map<char, STATUS> state;
	for (auto& item : graph) state[item.first] = NOT_VISITED;
	string result;
	stack<char> topOrder;
	for (auto& item : graph) {
		if (state[item.first] == VISITED)
			continue;
		if (!fillOrder(topOrder, state, item.first))
			return result;
	}

	while (!topOrder.empty()) {
		result.push_back(topOrder.top());
		topOrder.pop();
	}
	return result;
}





