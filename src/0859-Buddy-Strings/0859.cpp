class Solution {
 public:
  bool buddyStrings(string s, string goal) {
    int n = s.size(), m = goal.size();
    if (n != m) return false;
    int a[26] = {};
    int b[26] = {};
    int t = 0;
    for (int i = 0; i < n; i++) {
      a[s[i] - 'a']++, b[goal[i] - 'a']++;
      if (s[i] != goal[i]) t++;
    }
    bool ok = false;
    for (int i = 0; i < 26; i++) {
      if (a[i] != b[i]) return false;
      if (a[i] > 1) ok = true;
    }
    return t == 2 || (t == 0 && ok);
  }
};