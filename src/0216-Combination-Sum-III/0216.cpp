#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> path;
        _combinationSum3(nums, n, 0, path, res, k);
        return res;
    }
private:
    void _combinationSum3(vector<int>& candidates, int target, int index, vector<int>& path, vector<vector<int>>& res, int k)
    {
        if (target == 0 and path.size() == k)
        {
            res.push_back(path);
            return;
        }
        if (!path.empty() and target < *(path.end() - 1)) return;
        for (unsigned int i = index; i < candidates.size(); ++i)
        {
            if (i > index and candidates[i] == candidates[i - 1]) continue;
            path.push_back(candidates[i]);
            _combinationSum3(candidates, target - candidates[i], i + 1, path, res, k);
            path.pop_back();
        }
    }
};