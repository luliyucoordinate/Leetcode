class Solution 
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        int cnt[101] = {};
        for (int i : nums) cnt[i]++;
        for (int i = 1; i < 101; i++) cnt[i] += cnt[i - 1];
        
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] != 0) res[i] = cnt[nums[i] - 1];
        }
        return res;
    }
};