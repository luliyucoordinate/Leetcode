class Solution 
{
public:
    int minBuildTime(vector<int>& blocks, int split) 
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i : blocks) q.push(i);
        while (q.size() > 1)
        {
            q.pop();
            int y = q.top(); q.pop();
            q.push(y + split);
        }
        return q.top();
    }
};