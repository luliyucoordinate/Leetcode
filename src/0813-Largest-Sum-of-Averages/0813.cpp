class Solution {
 public:
  double largestSumOfAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<double> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] + nums[i - 1];
    }

    vector<double> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      f[i] = p[i] / i;
    }
    for (int i = 2; i <= k; i++) {
      for (int j = n; j >= i; j--) {
        for (int z = i - 1; z < j; z++) {
          f[j] = max(f[j], f[z] + (p[j] - p[z]) / (j - z));
        }
      }
    }
    return f[n];
  }
};