#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numDecodings(string s) 
    {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        if (s.size() == 1) if (s[0] != '0') return 1;

        vector<int> mem(s.size() + 1, 0);
        mem[0] = s[0] != '0' ? 1 : 0;
        mem[1] = s[1] != '0' ? 1 : 0;
        for (unsigned int i = 2; i < s.size() + 1; ++i)
        {
            int prev = s[i - 1] - '0';
            if (prev >= 1 and prev <= 9) 
                mem[i] += mem[i - 1];
            
            int tail = stoi(s.substr(i-2, 2));
            if (tail >= 10 and tail <= 26)
                mem[i] += mem[i - 2];
        }
        return mem[mem.size() - 1];
    }
};