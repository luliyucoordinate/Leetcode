#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();
        vector<int> result(2, -1);
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (nums[mid] >= target)
            {
                if (nums[mid] == target) result[0] = mid;
                r = mid;
            }
            else l = mid + 1;
        }
        l = 0; r = nums.size();
        while (l < r)
        {
            int mid = (r - l)/2 + l;
            if (nums[mid] > target) r = mid;
            else
            {
                if (nums[mid] == target) result[1] = mid;
                l = mid + 1;
            }
        }
        return result;
    }
};
int main()
{
    vector<int> arr = { 3, 2, 2, 3};
    int target = 8;
    auto result = Solution().searchRange(arr, target);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}