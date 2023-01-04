class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (auto& task : tasks) cnt[task]++;
    int res = 0;
    for (auto& [k, v] : cnt) {
      if (v == 1) return -1;
      res += (v + 2) / 3;
    }
    return res;
  }
};