#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (m.count(target - nums[i]))
            {
                return { m[target - nums[i]] , i };
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    const int nums[] = { 0,4,3,0 };
    vector<int> nums_vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 7;
    for (int v : Solution().twoSum(nums_vec, target))
    {
        std::cout << v << std::endl;
    }
    return 0;
}