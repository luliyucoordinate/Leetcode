class Solution {
 public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    vector<string> a, b;
    stringstream s1(sentence1);
    stringstream s2(sentence2);
    string cur;
    while (s1 >> cur) {
      a.push_back(cur);
    }

    while (s2 >> cur) {
      b.push_back(cur);
    }
    int n = a.size() - 1, m = b.size() - 1, i = 0, j = 0;
    while (i <= n && j <= m) {
      if (a[i] != b[j] && a[n] != b[m]) {
        break;
      } else if (a[i] == b[j]) {
        i++, j++;
      } else {
        n--, m--;
      }
    }
    return i > n || j > m;
  }
};