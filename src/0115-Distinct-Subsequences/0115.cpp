#include <iostream>
#include <string>
#include <vector>
using namespace std;


static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numDistinct(string s, string t) 
    {
        vector<int> mem(t.size()+1, 0);
        mem[0] = 1;
        for (auto s_c : s)
        {
            for (int i = t.size() - 1; i >= 0; --i)
            {
                if (t[i] == s_c) mem[i+1] += mem[i];
            }
        }
        return *mem.rbegin();
    }
};
int main(int argc, char const *argv[])
{
    string s = "rabbbit";
    string t = "rabbit";
    cout << Solution().numDistinct(s, t);
    return 0;
}
