#include <iostream>
#include <vector>
#include <unordered_map>
using  namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int result = 0, cur_sum = 0;
        unordered_map<int, int> sum_dict = {{0, 1}};
        for (auto& num : nums)
        {
            cur_sum += num;
            result += sum_dict[cur_sum - k];
            sum_dict[cur_sum]++;
        }
        return result;
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    int k = 3;
    cout << Solution().subarraySum(nums, k);
    return 0;
}
