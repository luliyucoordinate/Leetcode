#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        unsigned int n = matrix.size();
        for(unsigned int i = 0; i < n/2; ++i)
        {
            for(unsigned int j = i; j < n - 1 - i; ++j)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
int main()
{
    vector<vector<int>> matrix = {
                                {1,2,3},
                                {4,5,6},
                                {7,8,9}
                                };
    Solution().rotate(matrix);
    return 0;
}