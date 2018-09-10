#include <vector>
#include <iostream>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        int count = p.size();
        int pChar[256] = { 0 };
        vector<int> result;
        for (auto& i : p)
        {
            ++pChar[i];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (pChar[s[i]] >= 1) --count;
            --pChar[s[i]];
            if (i >= p.size())
            {
                if (pChar[s[i - p.size()]] >= 0) ++count;
                ++pChar[s[i - p.size()]];
            }
            if (count == 0) result.push_back(i - p.size() + 1);
        }
        return result;
    }
};
int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    for (auto& i : Solution().findAnagrams(s, p))
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}