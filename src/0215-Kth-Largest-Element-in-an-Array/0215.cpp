#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        int l = 0, r = nums.size() - 1;
        while (true)
        {
            int p = _partition(nums, l, r);
            if (p == k - 1) return nums[p];
            if (p > k - 1) r = p - 1;
            else l = p + 1;
        }
    }
private:
    int _partition(vector<int>& nums, int l, int r)
    {
        int j = (rand() % (r - l + 1)) + l;
        swap(nums[l], nums[j]);
        j = l;
        for (int i = l + 1; i <= r; ++i)
        {
            if (nums[i] > nums[l])
            {
                ++j;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[l], nums[j]);
        return j;
    }
};
int main()
{    
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << Solution().findKthLargest(nums, k);
}