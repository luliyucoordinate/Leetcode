class Solution {
 public:
  int numDifferentIntegers(string word) {
    unordered_set<string> res;
    int n = word.size();
    for (int i = 0; i < n; i++) {
      if (isdigit(word[i])) {
        string cur;
        while (i < n && isdigit(word[i])) {
          cur += word[i];
          i++;
        }
        int j = 0;
        for (; j < cur.size(); j++) {
          if (cur[j] != '0') break;
        }
        res.insert(cur.substr(j, cur.size() - j));
      }
    }
    return res.size();
  }
};