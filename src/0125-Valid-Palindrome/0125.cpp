#include <string>
#include <iostream>
#include <cctype>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        if (s.empty()) return true; 
        int s_size = s.size();
        int i = 0;
        while (i < s_size) 
        {
            if (!isalnum(s[s_size])) { s_size--; continue; }
            if (!isalnum(s[i])) { i++; continue; }   
            if (tolower(s[i++]) != tolower(s[s_size--])) return false;
        }
        return true;
    }
};
int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << Solution().isPalindrome(s) << endl;
    return 0;
}