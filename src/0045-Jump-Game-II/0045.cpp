#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        vector<int> steps(nums.size(), nums[0]);
        int step = 0;
        for (uint i = 1; i < nums.size(); ++i)
        {
            if (steps[step] >= nums.size() - 1) return step + 1;
            if (steps[step + 1] < i + nums[i]) steps[step + 1] = i + nums[i];
            if (steps[step] <= i) step++;
        }
        return step;
    }
};
int main()
{
    vector<int> nums = {3,4,-1,1};
    cout << Solution().jump(nums);
    return 0;
}
