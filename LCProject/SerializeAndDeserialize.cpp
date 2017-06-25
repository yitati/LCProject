#include <string>
#include <cstring>
using namespace std;

/*
1. We want to store one int to a 4 byte buffer
*/

// using memcpy is the golden rule regardless of big endian or small endian
string serializeGolden(int num)
{
	string result;
	char buff[4];
	int x = num;
	memcpy(buff, &x, sizeof(int));
	for (int i = 0; i < 4; i++)
	{
		result.push_back(buff[i]);
	}

	return result;
}


int deserializeFromStr(string str)
{
	int num;
	char * buff = &str[0];
	memcpy(&num, buff, sizeof(int));
	return num;
}
