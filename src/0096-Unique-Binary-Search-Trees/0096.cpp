#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int> mem(n + 1, 0);
        mem[0] = 1, mem[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                mem[i] += mem[j - 1]*mem[i - j];
            }
        }
        return *rbegin(mem);
    }
};
int main()
{
    return 0;
}