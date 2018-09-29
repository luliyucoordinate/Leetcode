#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        int result = 0;
        for (auto& i : nums) result += i;
        if (result & 1) return false;
        return _canPartition(nums, nums.size() - 1, result >> 1);
    }
private:
    bool _canPartition(vector<int>& nums, int index, int result)
    {
        if (result == 0) return true;
        if (result < 0 or index < 0 or nums[index] > result) return false;
        return _canPartition(nums, index - 1, result - nums[index]) or  
            _canPartition(nums, index - 1, result);
    }
};