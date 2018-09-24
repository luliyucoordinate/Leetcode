#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
            
        vector<vector<int>> mem(m, vector<int>(n, 0));
        mem[0][0] = 1;
        for (unsigned int i = 0; i < m; ++i)
        {
            for (unsigned int j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 0)
                {
                    if (j) mem[i][j] += mem[i][j - 1];
                    if (i) mem[i][j] += mem[i - 1][j];
                }
                else
                {
                    mem[i][j] = 0;
                }
            }
        }
        return mem[m - 1][n - 1];
    }
};

int main()
{
    return 0;
}