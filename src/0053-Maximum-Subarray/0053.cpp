#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        for (unsigned int i = 1; i < nums.size(); ++i)
        {
            if (nums[i-1] > 0) nums[i] += nums[i-1];
        }
        return *max_element(nums.begin(), nums.end());
    }
};
int main()
{
    vector<int> nums = {-1};
    cout << Solution().maxSubArray(nums);
}