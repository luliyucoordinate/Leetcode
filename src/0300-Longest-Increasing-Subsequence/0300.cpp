#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> tmp;
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            auto l = lower_bound(tmp.begin(), tmp.end(), nums[i]);
            if (l == tmp.end())
                tmp.push_back(nums[i]);
            else
                *l = nums[i];
        }
        return tmp.size();
    }
};
