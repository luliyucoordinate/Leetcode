class Solution {
 public:
  vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
    unordered_map<string, vector<int>> cnt;
    for (int i = 0; i < keyName.size(); i++) {
      auto& name = keyName[i];
      auto& time = keyTime[i];
      auto hour = (time[0] - '0') * 10 + (time[1] - '0');
      auto minute = (time[3] - '0') * 10 + (time[4] - '0');
      cnt[name].emplace_back(hour * 60 + minute);
    }

    vector<string> res;
    for (auto& [k, v] : cnt) {
      sort(v.begin(), v.end());
      for (int i = 2; i < v.size(); i++) {
        auto t1 = v[i - 2], t2 = v[i];
        auto x = t2 - t1;
        if (x <= 60) {
          res.emplace_back(k);
          break;
        }
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
