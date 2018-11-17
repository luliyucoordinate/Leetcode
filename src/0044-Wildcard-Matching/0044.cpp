#include <iostream>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isMatch(string s, string p) 
    {
        int i = 0, j = 0, star = -1, i_index = 0;
        while (i < s.size())
        {
            if (j < p.size() and (p[j] == '?' or p[j] == s[i]))
            {
                ++i; ++j;
            }
            else if (j < p.size() and p[j] == '*')
            {
                star = j++; i_index = i;
            }
            else if (star != -1)
            {
                j = star + 1;
                i = ++i_index;
            }
            else return false;
        }
        while (j < p.size() and p[j] == '*') ++j;
        return j == p.size();
    }
};
int main()
{
    string s = "aa";
    string p = "*";
    cout << Solution().isMatch(s, p);
    return 0;
}
