/******************************************************************************/
/*
* Question: #247 Strobogrammatic Number II
* company tag: Facebook, Google
* A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
* Find all strobogrammatic numbers that are of length = n.
* For example,
* Given n = 2, return ["11","69","88","96"].
*/
/*****************************************************************************/

#include <vector>

using namespace std;

vector<string> fillStroboNums(int n, int m)
{
    vector<string> results;
    if(m == 0)
    {
        results.push_back("");
        return results;
    }
    else if(m == 1)
    {
        results.push_back("0");
        results.push_back("1");
        results.push_back("8");
        return results;
    }
    vector<string> last = fillStroboNums(n, m-2);
    for(string str : last)
    {
        // if for the last layer, num cannot start with '0'
        if(n != m)
        {
            results.push_back("0" + str + "0");
        }
        results.push_back("1" + str + "1");
        results.push_back("8" + str + "8");
        results.push_back("6" + str + "9");
        results.push_back("9" + str + "6");
    }
    return results;
}

vector<string> findStrobogrammatic(int n)
{
    return fillStroboNums(n, n);
}
