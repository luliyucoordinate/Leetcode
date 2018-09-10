#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int l = 0;
        int r = 0;
        int maxLength = 0;
        int usedChar[256] = { 0 };
        while (l < s.size())
        {
            if (r < s.size() && usedChar[s[r]] == 0)
            {
                usedChar[s[r++]] += 1;
            }
            else
            {
                usedChar[s[l++]] -= 1;
            }
            maxLength = max(maxLength, r - l);
        }
        return maxLength;
    }
};
int main()
{
    string s = "abcabcbb";
    cout << Solution().lengthOfLongestSubstring(s) << endl;
    return 0;
}