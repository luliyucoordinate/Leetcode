class RandomizedSet {
 public:
  RandomizedSet() {}

  bool insert(int val) {
    if (m.count(val)) return false;
    n.push_back(val);
    m[val] = n.size() - 1;
    return true;
  }

  bool remove(int val) {
    if (!m.count(val)) return false;
    m[n.back()] = m[val];
    n[m[val]] = n.back();
    n.pop_back();
    m.erase(val);
    return true;
  }

  int getRandom() { return n[rand() % n.size()]; }
  unordered_map<int, int> m;
  vector<int> n;
};