class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> f(n, vector<int>(n, 0));
    unordered_map<int, vector<int>> idx;
    for (int i = 0; i < n; i++) {
      idx[nums[i]].push_back(i);
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        auto p = 2ll * nums[j] - nums[i];
        if (p > INT_MAX || p < INT_MIN) continue;
        for (auto& x : idx[p]) {
          if (x < j) {
            f[i][j] += f[j][x] + 1;
          }
        }
        res += f[i][j];
      }
    }
    return res;
  }
};