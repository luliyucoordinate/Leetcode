class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        int l = m, r = m * 5000, res = -1;
        
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            int cnt = dfs(mat, 0, mid, 0, k);
            if (cnt >= k) {
                res = mid, r = mid - 1;
            } else {
                l = mid;
            }
        }
        return res;
    }
private:
    int m, n;
    
    int dfs(vector<vector<int>>& mat, int cur, int target, int r, int k) {
        if (cur > target) return 0;
        if (r == m) return 1;
        
        int res = 0;
        for (int c = 0; c < n; c++) {
            int cnt = dfs(mat, cur + mat[r][c], target, r + 1, k - res);
            if (cnt == 0) break;
            res += cnt;
            if (res > k) break;
        }
        return res;
    }
};