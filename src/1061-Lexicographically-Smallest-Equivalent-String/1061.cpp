class Solution {
 public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int m[26] = {};
    iota(m, m + 26, 0);

    function<int(int)> find = [&](int x) {
      if (x != m[x]) {
        m[x] = find(m[x]);
      }
      return m[x];
    };
    int n = s1.size();
    for (int i = 0; i < n; i++) {
      int a = s1[i] - 'a', b = s2[i] - 'a';
      auto x = find(a), y = find(b);
      m[max(x, y)] = min(x, y);
    }

    string res = baseStr;
    for (int i = res.size() - 1; ~i; i--) {
      res[i] = find(res[i] - 'a') + 'a';
    }
    return res;
  }
};