static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isUgly(int num) 
    {
        vector<int> nums = {2, 3, 5};
        for (int i : nums) 
        {
            while (num > 0 and num%i == 0)
            {
                num /= i;
            }
        }
        return num == 1;
    }
};