#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int l = 0;
        int r = numbers.size() - 1;
        while (l < r)
        {
            if (numbers[l] + numbers[r] == target)
            {
                return { l + 1, r + 1 };
            }
            else if (numbers[l] + numbers[r] < target)
            {
                ++l;
            }
            else
            {
                --r;
            }
        }
        return {};
    }
};
int main()
{    
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    for (auto& num : Solution().twoSum(numbers, target))
        cout << num << endl;
    return 0;
}