class Solution {
 public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    vector<string> res;
    int n = folder.size();
    for (int i = 0, j = 1; i < n; j++) {
      res.emplace_back(folder[i]);
      auto a = folder[i].size();
      while (j < n && a < folder[j].size() && folder[j][a] == '/' &&
             folder[j].substr(0, a) == folder[i])
        j++;
      i = j;
    }
    return res;
  }
};