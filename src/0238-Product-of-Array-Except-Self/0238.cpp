#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> result(nums.size(), 1);
        for (unsigned int i = 0; i < nums.size()-1; ++i)
        {
            result[i+1] = result[i]*nums[i];
        }
        int right = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {1,2,3,4};
    auto result = Solution().productExceptSelf(nums);
    return 0;
}