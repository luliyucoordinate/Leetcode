class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = 0, degree = 0;
        unordered_map<int, int> cnt, first;
        for (int i = 0; i < n; i++) {
            if (!first.count(nums[i])) first[nums[i]] = i;
            cnt[nums[i]]++;
            if (cnt[nums[i]] > degree) {
                degree = cnt[nums[i]];
                res = i - first[nums[i]] + 1;
            } else if (cnt[nums[i]] == degree) {
                res = min(res, i - first[nums[i]] + 1);
            }
        }
        return res;
    }
};