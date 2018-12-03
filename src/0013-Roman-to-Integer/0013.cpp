#include <string>
#include <unordered_map>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    int romanToInt(string s) 
    {
        unordered_map<char, int> s_dict = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0, pre = 0;
        for (auto ch : s)
        {
            auto cur = s_dict[ch];
            if (pre < cur) res += (cur - 2*pre);
            else res += cur;
            pre = cur;
        }
        return res;
    }
};