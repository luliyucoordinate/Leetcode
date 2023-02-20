class Solution {
 public:
  string bestHand(vector<int>& ranks, vector<char>& suits) {
    vector<int> a(14);
    for (auto& x : ranks) a[x]++;

    int i = suits.size() - 1, j = i;
    while (~j && suits[i] == suits[j]) j--;
    if (j == -1) return "Flush";

    for (auto v : a) {
      if (v >= 3) return "Three of a Kind";
    }
    for (auto v : a) {
      if (v == 2) return "Pair";
    }
    return "High Card";
  }
};