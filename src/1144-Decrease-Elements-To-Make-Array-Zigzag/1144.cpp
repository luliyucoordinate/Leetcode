class Solution 
{
public:
    int movesToMakeZigzag(vector<int>& nums) 
    {
        int res[2] = {};
        nums.insert(nums.begin(), INT_MAX); nums.push_back(INT_MAX);
        for (int i = 1; i < nums.size() - 1; ++i)
        {
            res[i % 2] += max(0, nums[i] - min(nums[i-1], nums[i+1]) + 1);
        }
        return min(res[0], res[1]);
    }
};