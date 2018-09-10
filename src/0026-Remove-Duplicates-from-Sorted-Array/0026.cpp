#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int k = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                 nums[k++] = nums[i];
            }
        }
        return k;
    }
};
int main()
{
    int arr[] = {0,0,1,1,1,1,2,3,3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    int ret = Solution().removeDuplicates(vec);
    cout << ret << endl;
    return 0;
}