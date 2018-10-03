#include <iostream>
#include <string>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        vector<int> mem(s.size() + 1, 0);
        mem[0] = true;
        for (unsigned int i = 1; i < s.size() + 1; ++i)
        {
            for (auto& word : wordDict)
            {
                if (i >= word.size() && mem[i - word.size()] &&
                    word == s.substr(i - word.size(), word.size()))
                {
                    mem[i] = true;
                    break;
                }
            }
        }
        return *mem.rbegin();
    }
};