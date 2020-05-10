class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd, mind;
        int i = 0;
        
        for (int a : nums) {
            while (maxd.size() && a > maxd.back()) maxd.pop_back();
            while (mind.size() && a < mind.back()) mind.pop_back();
            maxd.emplace_back(a);
            mind.emplace_back(a);
            
            if (maxd[0] - mind[0] > limit) {
                if (maxd[0] == nums[i]) maxd.pop_front();
                if (mind[0] == nums[i]) mind.pop_front();
                i++;
            }
        }
        return nums.size() - i;
    }
};