#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
        int mask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        mask &= -mask;
        vector<int> result(2, 0); 
        for (int num : nums)
        {
            if ((num & mask) == 0) 
            {
                result[0] ^= num;
            }
            else 
            {
                result[1] ^= num;
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {1,2,1,3,2,5};
    auto result = Solution().singleNumber(nums);
    return 0;
}