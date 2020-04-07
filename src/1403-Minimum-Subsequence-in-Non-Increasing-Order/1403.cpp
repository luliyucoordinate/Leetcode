class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int cur = 0, t = accumulate(nums.begin(), nums.end(), 0) / 2;
        
        for (int i = nums.size() - 1; ~i; i--) {
            cur += nums[i];
            res.emplace_back(nums[i]);
            if (cur > t) return res;
        }
        return res;
    }
};