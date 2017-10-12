/*
 * SparseVectorDotProduct.cpp
利口叁妖妖，简化了下，直接1行乘以一列，问怎么建立数据结构存储数据。
这题之前没写过，我的解决方案是：建立链表，存储那些值不为0的数据及其index。
然后双指针遍历两条链表，只有当index相同时，才相乘
 */


/*
vector<int> input1 = {1, 0, 0, 0, 7, 8}
vector<int> input2 = {3, 0, 1, 0, 1, 0}
*/

#include <vector>

using namespace std;
/*
 use two pair vector to store the input pair<int, int> be the index - value pairs
 */

vector<int> dotProduct(vector<int> input1, vector<int> input2) {
	vector<pair<int, int>> array1;
	vector<pair<int, int>> array2;

	int len = input1.size();

	for (int i = 0; i < len; i++) {
		if (input1[i] != 0)
			array1.push_back(make_pair(i, input1[i]));
		if (input2[i] != 0)
			array2.push_back(make_pair(i, input2[i]));
	}

	vector<pair<int, int>> product;
	vector<int> result(len, 0);
	int i = 0, j = 0;
	while (i < array1.size() && j < array1.size()) {
		if (array1[i].first < array2[j].first)
			i++;
		else if (array1[i].first > array2[j].first)
			j++;
		else {
			product.push_back(
					make_pair(array1[i].first,
							array1[i].second * array2[j].second));
			i++;
			j++;
		}
	}

	for (int i = 0; i < product.size(); i++) {
		result[product[i].first] = product[i].second;
	}

	return result;
}

int main(int argc, char ** argv) {
	vector<int> input1 = { 0, 1, 0, 0, 9, 8, 0, 0, 0, 5, 0, 4, 0 };
	vector<int> input2 = { 1, 0, 0, 8, 6, 0, 9, 0, 0, 0, 3, 0, 1 };

	vector<int> result = dotProduct(input1, input2);

	for (int num : result) {
		cout << num << "  ";
	}
}



