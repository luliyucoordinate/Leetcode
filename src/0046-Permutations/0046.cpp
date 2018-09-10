#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        if (nums.size() <= 1) return vector<vector<int>>{nums};
        vector<vector<int>> out;
        auto tmpNums = vector<int>(nums.begin() + 1, nums.end());
        auto perms = permute(tmpNums);
        for (auto& perm : perms)
        {
            for (unsigned int i = 0; i <= perm.size(); ++i)
            {
            	auto tmp_perm = perm;
            	tmp_perm.insert(tmp_perm.begin() + i, nums[0]);
                out.push_back(tmp_perm);
            }
        }
        return out;
    }
};