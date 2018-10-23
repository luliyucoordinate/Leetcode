#include <iostream>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return ;
        bool flag = false;
        unsigned int r = matrix.size(), c = matrix[0].size();
        for (unsigned int i = 0; i < r; ++i)
        {
            if (matrix[i][0] == 0) flag = true;
            for (unsigned int j = 1; j < c; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (unsigned int i = 1; i < r; ++i)
        {
            for (unsigned int j = 1; j < c; ++j)
            {
                if (!matrix[i][0] or !matrix[0][j]) matrix[i][j] = 0;
            }
        }
        if (matrix[0][0] == 0)
        {
            for (unsigned int j = 0; j < c; ++j) 
                matrix[0][j] = 0;
        }
        if (flag) 
        {
            for (unsigned int i = 0; i < r; ++i) 
                matrix[i][0] = 0;
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {{1,0,2,2}, {3,4,5,2}, {1,2,0,5}};
    Solution().setZeroes(matrix);
    return 0;
}