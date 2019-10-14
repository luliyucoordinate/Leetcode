class Solution 
{
public:
    int maxEqualFreq(vector<int>& nums) 
    {
        unordered_map<int, int> f;
        int n = nums.size(), res = 0;
        int k[n + 1] = {};
        for (int i = 1; i <= n; i++)
        {
            int a = nums[i-1];
            k[f[a]]--, f[a]++,k[f[a]]++;
            int t = f[a];
            if (k[t] * t == i and i < n) res = i + 1;
            else
            {
                int d = i - k[t] * t;
                if ((d == 1 or d == t + 1) and k[d] == 1) res = i;
            }
        }
        return res;
    }
};