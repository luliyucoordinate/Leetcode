class BrowserHistory {
 public:
  BrowserHistory(const string& homepage) { a.push_back(homepage); }

  void visit(const string& url) {
    a.push_back(url);
    if (!b.empty()) b.clear();
  }

  string back(int steps) {
    while (steps-- && a.size() > 1) {
      auto& x = a.back();
      b.push_back(x);
      a.pop_back();
    }
    return a.back();
  }

  string forward(int steps) {
    while (steps-- && !b.empty()) {
      auto& x = b.back();
      a.push_back(x);
      b.pop_back();
    }
    return a.back();
  }
  vector<string> a, b;
};