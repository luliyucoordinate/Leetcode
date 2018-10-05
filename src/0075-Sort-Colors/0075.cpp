#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int zeros = 0, ones = 0;
        for (unsigned int i = 0;i < nums.size(); ++i)
        {
            if (nums[i] == 0) ++zeros;
            if (nums[i] == 1) ++ones; 
        }
        for (unsigned int i = 0; i < nums.size(); ++i)
        {
            if (i < zeros) nums[i] = 0;
            if ((i >= zeros) and (i < (zeros + ones))) nums[i] = 1;
            if (i >= (zeros + ones)) nums[i] = 2;
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