class Solution {
 public:
  vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
    int n = queries.size();
    vector<int> res(n);
    sort(nums.begin(), nums.end());
    nums.insert(nums.begin(), 0);
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1];
    }
    for (int i = 0; i < n; i++) {
      res[i] =
          upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin() - 1;
    }
    return res;
  }
};