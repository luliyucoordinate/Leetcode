#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            if (++digits[i] %= 10)
                return digits;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};
int main()
{
    vector<int> digits = {0};
    auto result = Solution().plusOne(digits);
    return 0;
}