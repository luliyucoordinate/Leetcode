#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& data) 
    {
        if (data.empty()) return 0;
        int m = data.size(), n = data[0].size();
        vector<vector<unsigned int>> mem(m, vector<unsigned int>(n, 0));
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                if (data[i][j] == 1) continue;
                if (i > 0 and j > 0) mem[i][j] = mem[i-1][j] + mem[i][j-1];
                else if (i) mem[i][j] = mem[i-1][j];
                else if (j) mem[i][j] = mem[i][j-1];
                else mem[i][j] = 1;
            }
        }
        return mem[m-1][n-1];
    }
};
int main()
{
    return 0;
}