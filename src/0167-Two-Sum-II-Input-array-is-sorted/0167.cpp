#include <iostream>
#include <vector>
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
            int sum = numbers[l] + numbers[r];
            int diff = sum - target;
            if (diff == 0) return { l + 1, r + 1 };
            else if (diff < 0) ++l;
            else --r;
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