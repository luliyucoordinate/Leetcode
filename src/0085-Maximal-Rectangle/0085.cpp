#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<int> heights(c+1, 0);
        int res = 0;
        
        for (auto& row : matrix)
        {
            for (int i = 0; i < c; ++i)
            {
                heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
            }
            vector<int> s{-1};
            for (int idx = 0; idx < c+1; ++idx)
            {
                while (heights[idx] < heights[s.back()])
                {
                    int h = heights[s.back()]; s.pop_back();
                    res = max(res, h*(idx - s.back() - 1));
                }
                s.push_back(idx);
            }
        }
        return res;
    }
};