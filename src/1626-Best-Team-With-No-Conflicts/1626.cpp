class Solution {
 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int res = 0;
    int n = scores.size();
    vector<pair<int, int>> cnt(n);
    for (int i = 0; i < n; i++) {
      cnt[i] = {ages[i], scores[i]};
    }
    sort(cnt.begin(), cnt.end());
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
      f[i] = cnt[i].second;
      for (int j = 0; j < i; j++) {
        if (cnt[i].second >= cnt[j].second)
          f[i] = max(f[i], f[j] + cnt[i].second);
      }
      res = max(res, f[i]);
    }
    return res;
  }
};