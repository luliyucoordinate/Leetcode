class Solution {
 public:
  int finalValueAfterOperations(vector<string>& operations) {
    int res = 0;
    for (auto& op : operations) {
      if (op[1] == '+')
        res++;
      else
        res--;
    }
    return res;
  }
};