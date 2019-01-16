#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        vector<int> stack;
        vector<int> res(nums.size(), -1);
        for (int i = 0; i < nums.size()*2; ++i)
        {
            while (!stack.empty() and nums[stack.back()] < nums[i%nums.size()])
            {
                res[stack.back()] = nums[i%nums.size()]; stack.pop_back();
            }
            stack.push_back(i%nums.size());
        }
        return res;
    }
};