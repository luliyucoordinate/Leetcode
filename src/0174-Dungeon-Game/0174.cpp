#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> mem(row, vector<int>(col, 0));
        
        for (int i = row-1; i > -1; --i)
        {
            for (int j = col-1; j > -1; --j)
            {
                if (i == row-1 and j == col-1)
                {
                    mem[i][j] = max(0, -dungeon[i][j]);    
                }
                else if (i == row-1)
                {
                    mem[i][j] = max(0, mem[i][j+1] - dungeon[i][j]);
                }
                else if (j == col-1)
                {
                    mem[i][j] = max(0, mem[i+1][j] - dungeon[i][j]);
                }
                else
                {
                    mem[i][j] = max(0, min(mem[i+1][j], mem[i][j+1]) - dungeon[i][j]);
                }
            }
        }
        return mem[0][0] + 1;
    }
};