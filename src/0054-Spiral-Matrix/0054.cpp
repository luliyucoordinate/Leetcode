#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> result;
        if (matrix.empty())
            return result;
        int x1 = 0, y1 = 0, x2 = matrix[0].size()-1, y2 = matrix.size()-1;
        while (x1 <= x2 and y1 <= y2) 
        {
            for (int c = x1; c <= x2; c++) result.push_back(matrix[y1][c]);
            for (int r = y1 + 1; r <= y2; r++) result.push_back(matrix[r][x2]);
            if (x1 < x2 and y1 < y2) 
            {
                for (int c = x2 - 1; c > x1; c--) result.push_back(matrix[y2][c]);
                for (int r = y2; r > y1; r--) result.push_back(matrix[r][x1]);
            }
            x1++;x2--;y1++;y2--;
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {-1};
    cout << Solution().spiralOrder(nums);
}