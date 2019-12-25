class Solution 
{
public:
    int findNumbers(vector<int>& nums) 
    {
        int res = 0;
        for (int n : nums)
        {
            int x = 0;
            while (n) n /= 10, x++;
            if (x % 2 == 0) ++res;
        }
        return res;
    }
};