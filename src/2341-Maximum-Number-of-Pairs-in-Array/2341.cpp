class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    int a[101] = {};
    for (auto x : nums) {
      a[x]++;
    }
    int res = 0;
    for (int i = 0; i <= 100; i++) {
      res += a[i] / 2;
    }
    return {res, (int)nums.size() - res * 2};
  }
};