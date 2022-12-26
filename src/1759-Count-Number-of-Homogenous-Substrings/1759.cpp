class Solution {
 public:
  int countHomogenous(string s) {
    long long res = 0;
    int i = 0, p = 0, n = s.size(), mod = 1e9 + 7;

    while (i < n) {
      while (i < n && s[p] == s[i]) i++;
      long long l = i - p;
      p = i;
      res = (res + (1 + l) * l / 2) % mod;
    }
    return res;
  }
};