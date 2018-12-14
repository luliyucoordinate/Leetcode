#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int totalNQueens(int n) 
    {
        int res = 0;
        vector<int> pos(n, -1);
        helper(pos, n, 0, res);
        return res;
    }
private:
    void helper(vector<int>& pos, int n, int row, int& res)
    {
        if(row == n) res++;
        else
        {
            for(int col = 0; col < n; col++)
            {
                if(isValid(pos, row, col))
                {
                    pos[row] = col;
                    helper(pos, n, row + 1, res);
                    pos[row] = -1;
                }
            }
        }
    }
    
    bool isValid(vector<int>& pos, int row, int col)
    {
        for(int i = 0; i < row; i++)
        {
            if (pos[i] == col or (row - i) == abs(col - pos[i]))
                return false;
        }
        return true;
    }
};