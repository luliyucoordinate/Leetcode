#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> result;
        if (n <= 0 or k <= 0 or n < k) return result;
        vector<int> nums;
        _combine(n, k, 1, nums, result);
        return result;
    }
private:
    void _combine(int n, int k, int start, vector<int> nums, vector<vector<int>>& result)
    {
        if (k == nums.size())
        {
            result.push_back(nums);
            return;
        }

        for (int i = start; i <= n - (k - nums.size()) + 1; ++i)
        {
            nums.push_back(i);
            _combine(n, k, i + 1, nums, result);
            nums.pop_back();
        }
    }
};