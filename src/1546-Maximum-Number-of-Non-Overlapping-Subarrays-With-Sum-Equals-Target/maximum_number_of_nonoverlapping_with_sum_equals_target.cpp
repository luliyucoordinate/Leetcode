/*************************************************************************************** 
 *
 * Given an array nums and an integer target.

 * Return the maximum number of non-empty non-overlapping subarrays such that the sum of values in each subarray is equal to target.
 * 
 * Example:
 * 
 * Given: nums = [1,1,1,1,1], target = 2
 * Return: 2
 * 
 * Given: nums = [-2,6,6,3,5,4,1,2,8], target = 10
 * Return: 3
 * 
 ***************************************************************************************/


class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        map<int,int>mp;
        int sum = 0;
        int res = 0;
        mp[0] = -1;
        int curr = -1;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp.find(sum-target) != mp.end())
            {
                int ind = mp[sum-target];
                if(curr <= ind)
                {
                    res++;
                    // mp[sum-target] = i;
                    curr = i;
                }
            }
            mp[sum] = i;
        }
        return res;
    }
};
