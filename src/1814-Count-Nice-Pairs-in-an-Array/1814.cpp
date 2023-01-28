class Solution {
 public:
  int countNicePairs(vector<int>& nums) {
    int mod = 1e9 + 7, res = 0;
    unordered_map<int, int> cnt;
    for (auto num : nums) {
      int x = 0, y = num;
      while (y) {
        x = x * 10 + y % 10;
        y /= 10;
      }
      res = (res + cnt[num - x]++) % mod;
    }
    return res;
  }
};