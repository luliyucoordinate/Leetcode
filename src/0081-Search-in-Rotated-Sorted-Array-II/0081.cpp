#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return false;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (high - low)/2 + low;
            if (target == nums[mid]) return true;
            if (nums[low] == nums[mid]) ++low;
            else if (nums[low] < nums[mid])
            {
                if (nums[low] <= target and target <= nums[mid])
                    high = mid - 1;
                else low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target and target <= nums[high])
                    low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }
};