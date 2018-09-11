#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> path;
        _subsetsWithDup(nums, 0, path, result);
        return result;
    }
private:
    void _subsetsWithDup(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& result) 
    {
        result.push_back(path);
        for (int i = index; i < nums.size(); ++i)
        {
            if (index < i and nums[i] == nums[i - 1]) continue;
            path.push_back(nums[i]);
            _subsetsWithDup(nums, i + 1, path, result);
            path.pop_back();
        }
    }
};