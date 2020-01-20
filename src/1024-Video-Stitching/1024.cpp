class Solution 
{
public:
    int videoStitching(vector<vector<int>>& clips, int T) 
    {
        int pre = -1, cur = 0, step = 0;
        sort(clips.begin(), clips.end());
        for (auto& it : clips)
        {
            if (cur >= T || it[0] > cur) break;
            if (pre < it[0] && it[0] <= cur)
            {
                step++, pre = cur;
            }
            cur = max(cur, it[1]);
        }
        return cur >= T ? step : -1;
    }
};