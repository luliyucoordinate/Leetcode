class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    int n = s.size(), m = p.size();
    if (n < m) return {};

    int cnt[26] = {};
    for (int i = 0; i < m; i++) cnt[p[i] - 'a']++;

    int t = m;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (cnt[s[i] - 'a'] >= 1) t--;
      cnt[s[i] - 'a']--;
      if (i >= m) {
        if (cnt[s[i - m] - 'a'] >= 0) t++;
        cnt[s[i - m] - 'a']++;
      }
      if (t == 0) res.emplace_back(i - m + 1);
    }
    return res;
  }
};