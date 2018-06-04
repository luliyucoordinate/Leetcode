#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;
        int c_char[26] = { 0 };
        for (int i = 0; i < s.size(); ++i)
        {
            ++c_char[s[i] - 'a'];
            --c_char[t[i] - 'a'];
        }
        for (int i = 0; i < 26; i++) 
        {
            if (c_char[i] != 0) return false;
        }
        return true;
    }
};
int main()
{
    string s = "anagram";
    string t = "nagaram";
    cout <<  Solution().isAnagram(s, t) << endl;
    return 0;
}