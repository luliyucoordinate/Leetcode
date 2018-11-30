#include <string>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 or s.size() < numRows) return s;
        vector<string> L(numRows, "");
        int index = 0, step = 1;
        for (auto ch : s)
        {
            L[index] += ch;
            if (index == 0) step = 1;
            else if (index == numRows - 1) step = -1;
            index += step;
        }
        string res;
        for (auto& s : L) res += s;
        return res;
    }
};