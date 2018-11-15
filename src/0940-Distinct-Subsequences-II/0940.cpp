#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int distinctSubseqII(string S) 
    {
        int ends[26] = {}, mod = 1e9 + 7;
        auto lambda = [&](int s, int i) { return (s + i) % mod; };
        for (auto c : S)
            ends[c - 97] = accumulate(begin(ends), end(ends), 1, lambda);
        return accumulate(begin(ends), end(ends), 0, lambda);
    }
};

int main()
{
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{4,1},{4,3}};
    cout << Solution().minAreaRect(points);
    return 0;
}
