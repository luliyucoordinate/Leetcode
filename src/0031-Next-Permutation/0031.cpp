#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i = nums.size()-1, j = i;
        while (i > 0 and nums[i] <= nums[i-1]) --i;
        --i;
        if (i >= 0)
        {
            while (j >= i and nums[j] <= nums[i]) --j;
            int tmp = nums[i];
            nums[i] = nums[j]; nums[j] = tmp;
        }
        ++i;
        reverse(nums.begin()+i, nums.end());
    }
};
int main()
{
    vector<int> arr = { 3, 2, 2, 3};
    Solution().nextPermutation(arr);
    return 0;
}