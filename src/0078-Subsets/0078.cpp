#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int n = pow(2, nums.size());
        for (int i = 0; i < n; i++) 
        {
            vector<int> tmp;
            for (unsigned int j = 0; j < nums.size(); j++) 
                if(i >> j & 1) tmp.push_back(nums[j]);
            result.push_back(tmp);
        }
        return result;
    }
};