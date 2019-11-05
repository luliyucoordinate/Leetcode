class Solution 
{
public:
    bool isGoodArray(vector<int>& nums) 
    {
        return accumulate(nums.begin(), nums.end(), nums[0], gcd<int, int>) == 1;
    }
};