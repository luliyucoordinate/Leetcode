#include <iostream>
#include <vector>
using namespace std;
 
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        if (nums.empty()) return {};
        int c1 = 0, c2 = 0, m = 0, n = 0;
        for (auto num : nums)
        {
            if (num == m) ++c1;
            else if (num == n) ++c2;
            else if (c1 == 0) 
            {
                m = num; ++c1;
            }
            else if (c2 == 0)
            {
                n = num; ++c2;
            }
            else
            {
                --c1; --c2;
            }
        }
        int count1 = 0, count2 = 0;
        for (auto num : nums)
        {
            if (num == m) ++count1;
            if (num == n) ++count2;
        }
        if (count1 > nums.size()/3 and count2 > nums.size()/3)
        {
            if (m == n) return {m};
            else return {m, n};
        }
        if (count1 > nums.size()/3) return {m};
        if (count2 > nums.size()/3) return {n};
        return {};
    }
};

int main()
{
    vector<int> nums = {0, -1, 2, 2, -1};
    auto result = Solution().majorityElement(nums);
    return 0;
}