#include <iostream>
#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (high - low)/2 + low;
            if (target == nums[mid]) return mid;
            if (nums[low] <= nums[mid])
            {
                if (nums[low] <= target and target <= nums[mid])
                    high = mid;
                else low = mid + 1;
            }
            else
            {
                if (nums[mid] <= target and target <= nums[high])
                    low = mid;
                else high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int target = 0;
    cout << Solution().search(arr, target);
    return 0;
}

