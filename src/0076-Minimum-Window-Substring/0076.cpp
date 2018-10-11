#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string minWindow(string s, string t) 
    {
        vector<int> mem(128, 0);
        for (auto& c : t) mem[c]++;
        unsigned int t_len = t.size();
        int minL = 0, minR = INT_MAX, l = 0;
        for (unsigned int r = 0; r < s.size(); ++r)
        {
            if (mem[s[r]]-- > 0) --t_len;
            if (t_len == 0)
            {
                while (mem[s[l]] < 0) ++mem[s[l++]];
                if (r - l < minR - minL) 
                {
                    minL = l; minR = r;
                }
                ++mem[s[l++]];
                ++t_len;
            }
        }
        return minR == INT_MAX ? "" : s.substr(minL, minR-minL+1);
    }
};
int main()
{
    string s = "ADOBECODEBANC", t = "ABC";
    cout << Solution().minWindow(s, t);
    return 0;
}