#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            while (nums[i] > 0 and nums[i] <= nums.size()
                and nums[nums[i] - 1] != nums[i])
            {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != i + 1) return i + 1;
        }
        return nums.size() + 1;
    }
};
int main()
{
    vector<int> nums = {3,4,-1,1};
    cout << Solution().firstMissingPositive(nums);
    return 0;
}
