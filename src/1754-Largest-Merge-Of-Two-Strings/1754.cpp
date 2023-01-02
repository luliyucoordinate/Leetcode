const int N = 6010;

int sa[N], x[N], y[N], c[N], rk[N], h[N];

void get_sa(const string& s, int n, int m) {
  for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[x[i]]--] = i;
  for (int k = 1; k <= n; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++) {
      if (sa[i] > k) y[++num] = sa[i] - k;
    }
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) {
      sa[c[x[y[i]]]--] = y[i];
      y[i] = 0;
    }
    swap(x, y);
    x[sa[1]] = 1, num = 1;
    for (int i = 2; i <= n; i++) {
      x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k])
                     ? num
                     : ++num;
    }
    if (num == n) break;
    m = num;
  }
}

void get_height(const string& s, int n) {
  for (int i = 1; i <= n; i++) rk[sa[i]] = i;
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    h[rk[i]] = k;
  }
}

class Solution {
 public:
  string largestMerge(string word1, string word2) {
    memset(sa, 0, sizeof sa);
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    memset(c, 0, sizeof c);
    memset(rk, 0, sizeof rk);
    memset(h, 0, sizeof h);

    int m = word1.size(), n = word2.size();
    string str = " " + word1 + "@" + word2;
    get_sa(str, n + m + 1, 122);
    get_height(str, n + m + 1);

    string res(n + m, ' ');
    int i = 0, j = 0;
    while (i < m || j < n) {
      auto k = i + j;
      if (i < m && rk[i + 1] > rk[m + 2 + j]) {
        res[k] = word1[i++];
      } else {
        res[k] = word2[j++];
      }
    }
    return res;
  }
};