#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxProduct(vector<int>& nums) 
    {
        auto numsB(nums);
        reverse(numsB.begin(), numsB.end());
        for (unsigned int i = 1; i < nums.size(); ++i)
        {
            if (nums[i-1]) nums[i] *= nums[i-1];
            if (numsB[i-1]) numsB[i] *= numsB[i-1];
        }
        int result = INT_MIN;
        for (auto num : numsB)
        {
            if (result < num) result = num;
        }
        for (auto num : nums)
        {
            if (result < num) result = num;
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {0, -2};
    cout << Solution().maxProduct(nums) << endl;
    return 0;
}