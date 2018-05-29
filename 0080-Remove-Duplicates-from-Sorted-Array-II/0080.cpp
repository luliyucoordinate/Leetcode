#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (k < 2 || nums[i] != nums[k - 2])
            {
                if (i != k)
                {
                    nums[k] = nums[i];
                    ++k;
                }
                else
                {
                    ++k;
                }
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