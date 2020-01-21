class Solution 
{
public:
    int minTaps(int n, vector<int>& ranges) 
    {
        vector<int> data(n + 1);
        for (int i = 0; i < ranges.size(); i++) 
        {
            int l = max(0, i - ranges[i]), r = min(n, i + ranges[i]);
            data[l] = max(data[l], r - l);
        }
        
        int pre = -1, cur = 0, step = 0;
        for (int i = 0; i <= n; i++) 
        {
            if (cur < i) return -1;
            if (cur >= n) return step;
            if (pre < i && i <= cur)
            {
                step++, pre = cur;
            }
            cur = max(cur, i + data[i]);
        }
        return step;
    }
};