#include <iostream>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (nums[mid] <= nums[mid + 1]) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
int main()
{
    vector<int> nums = {1,2,3,1};
    cout << Solution().findPeakElement(nums) << endl;
    return 0;
}