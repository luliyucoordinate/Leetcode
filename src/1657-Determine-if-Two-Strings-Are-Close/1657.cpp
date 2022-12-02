class Solution {
 public:
  bool closeStrings(string word1, string word2) {
    vector<int> f1(26), f2(26);
    for (auto c : word1) ++f1[c - 'a'];
    for (auto c : word2) ++f2[c - 'a'];

    for (int i = 0; i < 26; i++) {
      if ((f1[i] && !f2[i]) || (!f1[i] && f2[i])) return false;
    }

    unordered_map<int, int> freq;
    for (auto& f : f1) freq[f]++;
    for (auto& f : f2) freq[f]--;
    for (auto& [k, v] : freq) {
      if (v != 0) return false;
    }
    return true;
  }
};