class Solution {
 public:
  int beautySum(string s) {
    int res = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      int cnt[26] = {};
      int mx = 0;
      for (int j = i; j < n; j++) {
        cnt[s[j] - 'a']++;
        mx = max(mx, cnt[s[j] - 'a']);
        int mn = INT_MAX;
        for (int k = 0; k < 26; k++) {
          if (cnt[k]) {
            mn = min(mn, cnt[k]);
          }
        }
        res += mx - mn;
      }
    }
    return res;
  }
};