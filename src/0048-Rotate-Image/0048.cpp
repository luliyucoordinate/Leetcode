#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        reverse(matrix.begin(), matrix.end());
        for (unsigned int i = 0;i < matrix.size(); ++i)
        {
            for (unsigned int j = 0; j < i; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
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