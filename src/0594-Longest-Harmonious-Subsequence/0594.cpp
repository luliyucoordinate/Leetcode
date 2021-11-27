class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> cnt;
    int res = 0;
    for (int num : nums) cnt[num]++;
    for (auto& [k, v] : cnt) {
      if (cnt.count(k + 1)) {
        res = max(res, v + cnt[k + 1]);
      }
    }
    return res;
  }
};