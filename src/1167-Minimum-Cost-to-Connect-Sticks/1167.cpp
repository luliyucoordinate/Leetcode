class Solution 
{
public:
    int connectSticks(vector<int>& sticks) 
    {
        priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
        int res = 0;
        while (q.size() > 1) 
        {
            int a = q.top(); q.pop();
            int b = q.top(); q.pop();
            res += a + b;
            q.push(a + b);
        }
        return res;
    }
};