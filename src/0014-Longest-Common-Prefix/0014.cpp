#include <vector>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string res;
        if (strs.size() < 1) return res;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i + 1 > strs[j].size() or c != strs[j][i]) return res;
            }
            res.push_back(c);
        }
        return res;
    }
};