#include <string>
#include <iostream>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int len = s.size(), start = 0, maxLength = 1, left, right;
        for (unsigned int i = 0; i < len && len - i > maxLength / 2;) 
        {
            left = right = i;
            while (right < len - 1 && s[right + 1] == s[right]) ++right;
            i = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) 
            {
                ++right;
                --left;
            }
            if (maxLength < right - left + 1) 
            {
                start = left;
                maxLength = right - left + 1;
            }
        }
        return s.substr(start, maxLength);
    }
};
int main()
{
    string s = "babad";
    cout << Solution().longestPalindrome(s) << endl;
    return 0;
}