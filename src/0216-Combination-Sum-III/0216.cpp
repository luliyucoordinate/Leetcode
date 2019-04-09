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
        vector<vector<int>> res;
        vector<int> path;
        _combinationSum3(n, 1, path, res, k);
        return res;
    }
private:
    void _combinationSum3(int target, int index, vector<int>& path, vector<vector<int>>& res, int k)
    {
        if (target == 0 and path.size() == k)
        {
            res.push_back(path);
            return;
        }
        if (!path.empty() and target < path.back()) return;
        for (unsigned int i = index; i < 10; ++i)
        {
            path.push_back(i);
            _combinationSum3(target - i, i + 1, path, res, k);
            path.pop_back();
        }
    }
};