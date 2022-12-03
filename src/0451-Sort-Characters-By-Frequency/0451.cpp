class Solution {
 public:
  string frequencySort(string s) {
    vector<string> v(127);
    for (auto i : s) v[i] += i;
    sort(v.begin(), v.end(),
         [](const auto& s1, const auto& s2) { return s1.size() > s2.size(); });
    stringstream res;
    for (auto i : v) res << i;
    return res.str();
  }
};