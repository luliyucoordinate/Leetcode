#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int zero = -1;
        int two = nums.size();
        for (int i = 0; i < two;)
        {
            if (nums[i] == i) 
                ++i;
            else if (nums[i] == 2)            
                swap(nums[i], nums[--two]);
            else
            {
                assert(nums[i] == 0);
                swap(nums[++zero], nums[i++]);
            }
        }
    }
};
int main()
{
    int arr[] = {2,0,2,1,1,0};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().sortColors(vec);
    for (auto& num : vec)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}