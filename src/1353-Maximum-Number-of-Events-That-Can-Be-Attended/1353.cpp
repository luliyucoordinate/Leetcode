class Solution 
{
public:
    int maxEvents(vector<vector<int>>& events) 
    {
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0, index = 0, n = events.size();
        
        int l = 1e5, r = 0;
        for (auto& it : events)
        {
            l = min(it[0], l);
            r = max(it[1], r);
        }
        
        for (int i = l; i <= r; i++)
        {
            while (index < n && events[index][0] <= i)
                q.push(events[index++][1]);
            
            if (q.empty() && index == n) return res;
            
            while (!q.empty())
            {
                int pre = q.top(); q.pop();
                if (i <= pre)
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};