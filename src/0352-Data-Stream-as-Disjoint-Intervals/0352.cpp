class SummaryRanges {
 public:
  SummaryRanges() {}

  void addNum(int value) {
    auto q = cnt.lower_bound({value, value});
    if (q->first == value) return;
    auto p = q == cnt.begin() ? cnt.end() : prev(q);
    if (p != cnt.end() && q != cnt.end() && p->second + 1 == value &&
        q->first - 1 == value) {
      cnt.insert({p->first, q->second});
      cnt.erase(p);
      cnt.erase(q);
    } else if (p != cnt.end() && p->second + 1 == value) {
      cnt.insert({p->first, value});
      cnt.erase(p);
    } else if (p != cnt.end() && p->second + 1 > value) {
      return;
    } else if (q != cnt.end() && q->first - 1 == value) {
      cnt.insert({value, q->second});
      cnt.erase(q);
    } else {
      cnt.insert({value, value});
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> res;
    for (auto& v : cnt) {
      res.push_back({v.first, v.second});
    }
    return res;
  }

  set<pair<int, int>> cnt;
};