#include <iostream>
#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] != val)
            {
                if (i != k)
                    nums[k++] = nums[i];
                else
                    ++k;
            }
        }
        return k;
    }
};
int main()
{
    int arr[] = { 3, 2, 2, 3};
    vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    int val = 2;
    int ret = Solution().removeElement(vec, val);
    cout << ret << endl;
    return 0;
}