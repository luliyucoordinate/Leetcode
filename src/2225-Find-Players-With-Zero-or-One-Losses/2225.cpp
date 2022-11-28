class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_map<int, int> lost;
    for (const auto& m : matches) {
      if (!lost.count(m[0])) lost[m[0]] = 0;
      lost[m[1]]++;
    }

    vector<int> zero, ones;
    for (const auto& [k, l] : lost) {
      if (l == 0) zero.push_back(k);
      if (l == 1) ones.push_back(k);
    }

    sort(zero.begin(), zero.end());
    sort(ones.begin(), ones.end());
    return {zero, ones};
  }
};