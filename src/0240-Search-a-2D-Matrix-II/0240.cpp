static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        if (matrix.empty()) return false;
        int r = matrix.size(), c = matrix[0].size();
        int i = r-1, j = 0;
        while (i >= 0 and j < c)
        {
            if (matrix[i][j] == target) return true;
            else if (matrix[i][j] < target) ++j;
            else --i;
        }
        return false;
    }
};