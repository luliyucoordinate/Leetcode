class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<vector<int>> mat;
        int n = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> row = nums[i];
            for (int j = 0; j < row.size(); j++, n++) {
                if (i + j >= mat.size()) mat.push_back({});
                mat[i + j].emplace_back(row[j]);
            }
        }
        
        vector<int> res(n);
        for (auto& diag : mat) {
            for (int i = diag.size() - 1; i >= 0; i--) {
                res[k++] = diag[i];
            }
        }
        return res;
    }
};