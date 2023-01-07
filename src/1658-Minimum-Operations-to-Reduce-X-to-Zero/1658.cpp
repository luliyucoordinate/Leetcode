class Solution {
 public:
  int minOperations(vector<int>& nums, int t) {
    int x = accumulate(nums.begin(), nums.end(), 0) - t;
    if (x < 0) return -1;
    int res = -1, n = nums.size();
    for (int i = 0, j = 0, cur = 0; j < n;) {
      cur += nums[j++];
      while (cur > x) cur -= nums[i++];
      if (cur == x) res = max(res, j - i);
    }
    return res < 0 ? -1 : n - res;
  }
};