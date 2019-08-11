class Solution 
{
public:
    bool isMajorityElement(vector<int>& nums, int target) 
    {
        int cnt = 0;
        for (auto i : nums) if (i == target) cnt++;
        return cnt > nums.size() / 2;
    }
};