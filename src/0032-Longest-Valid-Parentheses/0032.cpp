#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int result = 0;
        vector<int> mem(s.size(), 0);
        for (int i = 1; i < s.size(); ++i)
        {
            if (s[i] == ')')
            {
                int left = i - 1 - mem[i-1];
                if (left >= 0 and s[left] == '(')
                {
                    mem[i] = mem[i-1] + 2;
                }
                if (i >= mem[i]) mem[i] += mem[i-mem[i]];
            }
            result = max(result, mem[i]);
        }
        return result;
    }
};
int main()
{
    return 0;
}