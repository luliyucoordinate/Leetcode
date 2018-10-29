#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minFallingPathSum(vector<vector<int>>& A) 
    {
        if (A.empty()) return 0;
        unsigned int r = A.size(), c = A[0].size();
        for (int row = r - 1; row > 0; --row)
        {
            for (unsigned int col = 0; col < c; ++col)
            {
                if (col == 0)
                    A[row - 1][col] += min(A[row][col], A[row][col + 1]);
                else if (col == c - 1)
                    A[row - 1][col] += min(A[row][col], A[row][col - 1]);
                else A[row - 1][col] += min(A[row][col], min(A[row][col + 1], A[row][col - 1]));
            }
        }
        return *min_element(A[0].begin(), A[0].end());
    }
};
int main()
{
    vector<vector<int>> nums = {{-19,57},{-40,-5}};
    cout << Solution().minFallingPathSum(nums);
    return 0;
}
