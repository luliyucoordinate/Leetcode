#include <iostream>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findMin(vector<int>& nums) 
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (high - low)/2 + low;
            if (nums[low] <= nums[mid])
            {
                if (nums[mid] <= nums[high]) return nums[low];
                else low = mid + 1;
            }
            else
            {
                if (nums[mid] <= nums[high]) high = mid;
            }
        }
        return nums[low];
    }
};
int main()
{
    vector<int> nums = {0, -2};
    cout << Solution().findMin(nums) << endl;
    return 0;
}