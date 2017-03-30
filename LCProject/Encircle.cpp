/* Encircle
* http://www.geeksforgeeks.org/check-if-a-given-sequence-of-moves-for-a-robot-is-circular-or-not/
Given a sequence of moves for a robot, check if the sequence is circular or not. A sequence of moves is circular 
if first and last positions of robot are same. A move can be one of the following.

  G - Go one unit
  L - Turn left
  R - Turn right 

Examples:

Input: path[] = "GLGLGLG"
Output: Given sequence of moves is circular 

Input: path[] = "GLLG"
Output: Given sequence of moves is circular 

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum direction {N=0, E, S, W};

bool isCircular(string command)
{
	int x = 0, y = 0;
	int dir = N;

	for (int i = 0; i < 4; i++)
	{
		for (char move : command)
		{
			if (move == 'R') dir = (dir + 1) % 4;
			else if (move == 'L') dir = (dir + 3) % 4;
			// if move is go then calculate current location
			else
			{
				if (dir == N) y++;
				else if (dir == E) x++;
				else if (dir == S) y--;
				else x--;
			}

			if (x == 0 && y == 0) return true;
		}

		if (x == 0 && y == 0) return true;
	}

	return (x == 0 && y == 0);
}


vector<string> enCircle(vector<string> commands)
{
	vector<string> result(commands.size());
	for (int i = 0; i < commands.size(); i++)
	{
		result.push_back(isCircular(commands[i]) ? "YES" : "NO");
	}

	return result;
}

/*

int main(int argc, char ** argv)
{
	vector<string> input;
	input.push_back("GRGRGR");
	input.push_back("L");
	input.push_back("LL");
	input.push_back("LLL");
	input.push_back("LLLL");
	input.push_back("G");
	input.push_back("GLGR");

	vector<string> output = enCircle(input);
	
	for (int i = 0; i < output.size(); i++)
	{
		cout << output[i] << endl;
	}

	system("pause");
}
*/