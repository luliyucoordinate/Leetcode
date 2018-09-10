// I think this solution is very beauty so l write it.
// class Solution 
// {

// public:
//     vector<vector<int>> threeSum(vector<int>& nums) 
//     {

//         unordered_map<int, int> nums_map;
//         for (int i = 0; i < nums.size(); i++)
//             nums_map[nums[i]] ++;

//         vector<vector<int>> result;

//         if (nums_map[0] >= 3)
//             result.push_back({ 0, 0, 0 });
//         // remove duplitation
//         sort(nums.begin(), nums.end());
//         auto iter = unique(nums.begin(), nums.end());
//         nums.erase(iter, nums.end());
//         for (auto& i : nums) cout << i << endl;
//         vector<int> neq;
//         vector<int> pos;
//         copy_if(nums.begin(), nums.end(), back_inserter(neq), [](int i) { return i < 0; });
//         copy_if(nums.begin(), nums.end(), back_inserter(pos), [](int i) { return i >= 0; });
        
//         for (auto& i : neq)
//         {
//             for (auto& j : pos)
//             {
//                 int dif = 0 - i - j;
//                 if (nums_map.count(dif))
//                 {
//                     if ((dif == i || dif == j) && nums_map[dif] >= 2)
//                     {
//                         result.push_back({ i, j, dif });
//                     }
//                     if (dif < i || dif > j)
//                     {
//                         result.push_back({ i, j, dif });
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result;
        int nums_len = nums.size();
        int left, right, dif;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums_len - 2; i++)
        {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue;
            left = i + 1;
            right = nums_len - 1;
            dif = -nums[i];

            while (left < right) 
            {
                if (nums[left] + nums[right] == dif) 
                {
                    result.push_back({ nums[i], nums[left], nums[right] });
                    ++left;
                    while (left < right && nums[left - 1] == nums[left]) ++left;
                    --right;
                }
                else if (nums[left] + nums[right] < dif) 
                {
                    ++left;
                }
                else 
                {
                    --right;
                }
            }
        }
        return result;
    }
};
int main()
{
    vector<int> s = { -1, 0, 1, 2, -1, -4 };
    for (auto& i : Solution().threeSum(s))
    {
        for (auto& j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}