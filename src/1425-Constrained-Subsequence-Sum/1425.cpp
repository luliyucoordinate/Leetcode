class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int res = -10000, n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = max(nums[i], nums[i] + (q.size() ? q.front() : 0));
            while (q.size() && nums[i] > q.back()) q.pop_back();
            q.emplace_back(nums[i]);

            if (i >= k && q.size() && q.front() == nums[i - k]) q.pop_front();
            res = max(res, nums[i]);
        }
        return res;
    }
};