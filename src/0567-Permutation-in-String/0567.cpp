class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    if (m < n) return false;

    int cnt[26] = {};
    for (int i = 0; i < n; i++) {
      cnt[s1[i] - 'a']++;
      cnt[s2[i] - 'a']--;
    }
    if (all_of(cnt, cnt + 26, [](auto& x) { return x == 0; })) return true;

    for (int i = n; i < m; i++) {
      cnt[s2[i] - 'a']--;
      cnt[s2[i - n] - 'a']++;
      if (all_of(cnt, cnt + 26, [](auto& x) { return x == 0; })) return true;
    }
    return false;
  }
};