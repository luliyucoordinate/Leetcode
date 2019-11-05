class Solution 
{
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size();
        auto atMost = [&](int k) {
            int res = 0, i = 0;
            for (int j = 0; j < n; j++)
            {
                k -= nums[j] % 2;
                while (k < 0)
                {
                    k += nums[i++] % 2;
                }
                res += j - i + 1;
            }
            return res;
        };
        return atMost(k) - atMost(k - 1);
    }
};