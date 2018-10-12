#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        vector<int> result;
        sort(nums.begin(), nums.end());
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            int l = i + 1, r = nums.size() - 1;
            int small = nums[l] + nums[l+1] + nums[i];
            int big = nums[r] + nums[r-1] + nums[i];
            if (small > target) result.push_back(small);
            else if (big < target) result.push_back(big);
            else
            {
                while (l < r)
                {
                    int tmp_sum = nums[l] + nums[r] + nums[i];
                    result.push_back(tmp_sum);
                    if (tmp_sum < target) ++l;
                    else if (tmp_sum > target) --r;
                    else return target;
                }
            }
        }
        sort(result.begin(), result.end(), [target](const int x1, const int x2){
            return abs(x1 - target) < abs(x2 - target);
        });
        return result[0];
    }
};
int main()
{
    vector<int> nums = { -1, 2, 1, -4};
    int target = 1;
    cout << Solution().threeSumClosest(nums, target);
    return 0;
}