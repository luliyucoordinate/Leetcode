
#include <iostream>
#include <vector>
#include <string>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        if (nums.size() == 0) return {};
        vector<string> result;
        int start = 0, end = 0, pre = 0, cur = 1;
        while (cur <= nums.size())
        {
            if (cur < nums.size() and nums[cur] - nums[pre] == 1)
            {
                cur++; pre++;
            }
            else
            {
                end = pre;
                if (end != start) result.push_back(to_string(nums[start]) 
                                                + "->" + to_string(nums[end]));
                else result.push_back(to_string(nums[start]));
                start = cur; ++cur; ++pre;
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {0,2,3,4,6,8,9};
    auto result = Solution().summaryRanges(nums);
    return 0;
}