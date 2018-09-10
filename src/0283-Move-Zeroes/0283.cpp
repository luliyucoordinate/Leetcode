#include <iostream>
#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        int k = 0; //[0,...,k)
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != 0)
            {
                nums[k++] = nums[i];
            }
        }
        for (int i = k; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};
int main()
{
    int arr[] = { 0, 1, 0, 3, 12 };
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    Solution().moveZeroes(vec);
    for (auto& i : vec)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}