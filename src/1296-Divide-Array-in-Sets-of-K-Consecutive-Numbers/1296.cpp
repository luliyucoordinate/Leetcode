class Solution 
{
public:
    bool isPossibleDivide(vector<int>& nums, int k) 
    {
        if (nums.size() % k != 0) return false;
        
        unordered_map<int, int> cnt;
        for (int n : nums) ++cnt[n];
        while (!cnt.empty())
        {
            for (int i = 1, n = min_element(cnt.begin(), cnt.end())->first; i <= k; ++i, ++n)
            {
                if (i < k && !cnt.count(n + 1)) return false;
                else if (--cnt[n] == 0) cnt.erase(n);
            }
        }
        return true;
    }
};