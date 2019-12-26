class Solution 
{
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        queue<int> q;
        for (int i : initialBoxes) q.push(i);
        int res = 0;

        while (!q.empty())
        {
            int changed = 0;
            for (int q_len = q.size(); q_len > 0; q_len--)
            {
                int b = q.front(); q.pop();
                if (status[b])
                {
                    changed = 1;
                    res += candies[b];
                    for (int i : containedBoxes[b]) q.push(i);
                    for (int i : keys[b]) status[i] = 1;
                } else q.push(b);
            }
            if (!changed) return res;
        }
        return res;    
    }
};