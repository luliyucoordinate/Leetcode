class Solution 
{
public:
    bool canPartition(vector<int>& nums) 
    {
        s = 0, n = nums.size();
        for (int i : nums) s += i;
        if (s % 2) return false;
        
        t = s / 2;
        vis = vector<int>(n);

        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(nums, 0, 0, 0);
    }
private:
    int n, s, t;
    vector<int> vis;
    
    bool dfs(vector<int>& nums, int cur, int u, int p)
    {
        if (u == 2) return true;
        if (cur == t) return dfs(nums, 0, u + 1, 0);
        
        for (int i = p, j; i < n; i++)
        {
            if (nums[i] + cur > t || vis[i]) continue;
            
            vis[i] = 1;
            if (dfs(nums, cur + nums[i], u, i + 1)) return true;
            vis[i] = 0;
            
            if (!cur || cur + nums[i] == t) return false;
            
            j = i;
            while (j < n && nums[i] == nums[j]) j++;
            i = j - 1;
        }
        return false;
    }
};