class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int cnt[101] = {};
    for (auto& num : nums) {
      cnt[num]++;
    }
    int res = 0;
    for (int i = 1; i <= 100; i++) res += cnt[i] ? 1 : 0;
    return res;
  }
};