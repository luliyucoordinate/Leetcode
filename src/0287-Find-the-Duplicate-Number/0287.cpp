#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findDuplicate(vector<int>& nums) 
    {
        int low = 1, high = nums.size() - 1;
        while (low < high)
        {
            int mid = (high - low)/2 + low;
            int count = 0;
            for (auto num : nums)
            {
                if (num <= mid) ++count;
            }
            if (count <= mid) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
int main(int argc, char const *argv[])
{
    vector<int> nums = {1,3,4,2,2,2};
    cout << Solution().findDuplicate(nums);
    return 0;
}
