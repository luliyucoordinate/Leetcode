class Solution {
 public:
  int minimumAverageDifference(vector<int>& nums) {
    int n = nums.size();
    long long total = 0;
    for (int i = 0; i < n; i++) {
      total += nums[i];
    }
    int a = -1, b = INT_MAX;
    long long l = 0;
    for (int i = 0; i < n; i++) {
      l += nums[i];
      auto r = total - l;
      auto l_avg = l / (i + 1);
      auto r_avg = n - i - 1 == 0 ? 0 : r / (n - i - 1);
      auto cur = abs(l_avg - r_avg);
      if (cur < b) {
        b = cur;
        a = i;
      }
    }
    return a;
  }
};