#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 3; ++i)
        {
            if (nums[i] << 2 > target) break;
            if (i > 0 and nums[i] == nums[i-1]) continue;
            for (int j = nums.size() - 1; j > i + 2; --j)
            {
                if (nums[j] << 2 < target) break;
                if (j < nums.size() - 1 and nums[j] == nums[j+1]) continue;
                int l = i + 1, r = j -1;
                while (l < r)
                {
                    if (target == nums[i] + nums[j] + nums[l] + nums[r])
                    {
                        res.push_back({nums[i], nums[l], nums[r], nums[j]});
                        while (l < r and nums[l] == nums[l+1]) ++l;
                        while (l < r and nums[r] == nums[r-1]) --r;
                        ++l; --r;
                    }
                    else if (target > nums[i] + nums[j] + nums[l] + nums[r]) ++l;
                    else --r;
                }
            }
        }
        return res;
    }
};