#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minFlipsMonoIncr(string S) 
    {
        int m = 0, n = 0;
        for (auto s : S)
        {
            m += s - '0';
            n = min(m, n + 1 - s + '0');
        }
        return n;
    }
};
int main()
{
    string S = "alex";
    cout << Solution().minFlipsMonoIncr(S);
    return 0;
}