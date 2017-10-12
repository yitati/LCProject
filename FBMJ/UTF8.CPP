/*
 * UTF8.CPP
 *
 *
http://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=296018&extra=page%3D1%26filter%3Dsortid%26sortid%3D311%26searchoption%5B3046%5D%5Bvalue%5D%3D2%26searchoption%5B3046%5D%5Btype%5D%3Dradio%26sortid%3D311
 */

#include <vector>
#include <string>

using namespace std;

bool validUtf8(vector<int>& data)
{
	int count = 0;
	for (int i = 0; i < data.size(); i++) {
		int x = data[i];
		if (count == 0)
		{
			if (x >> 5 == 0b0110) count = 1;
			else if (x >> 4 == 0b1110) count = 2;
			else if (x >> 3 == 0b11110) count = 3;
			else if (x >> 7 != 0) return false;
		}
		else {
			if (x >> 6 != 0b10) return false;
			else count--;
		}
	}
	return count == 0 ? true : false;
}

