#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isSubsequence(string s, string t) 
    {
        for (auto& per_s : s)
        {
            auto s_index_t = t.find(per_s);
            if (s_index_t == string::npos) return false;
            if (s_index_t == t.size() - 1) t = {};
            else t = t.substr(s_index_t + 1);
        }
        return true;
    }
};

int main()
{
    string s = "axc";
    string t = "ahbgdc";
    cout << Solution().isSubsequence(s, t);
    return 0;
}