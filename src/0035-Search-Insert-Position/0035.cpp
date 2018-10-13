#include <iostream>
#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (target > nums[mid]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 0;
    cout << Solution().searchInsert(nums, target);
    return 0;
}