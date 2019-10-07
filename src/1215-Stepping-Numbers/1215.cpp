class Solution 
{
public:
    vector<int> countSteppingNumbers(int low, int high) 
    {
        l = low, r = high;
        for (int i = 0; i <= 9; i++) bfs(i);
        sort(res.begin(), res.end());
        return res;
    }

private:
    int l, r;
    vector<int> res;
    
    void bfs(long long s)
    {
        queue<long long> q; q.push(s);
        while (!q.empty())
        {
            long long pre = q.front(); q.pop();
            if (pre >= l and pre <= r) res.push_back(pre);
            if (pre == 0 or pre > r) continue;
            int lt = pre % 10;
            long long s1 = pre * 10 + lt + 1, s2 = pre * 10 + lt - 1;
            if (lt == 0) q.push(s1);
            else if (lt == 9) q.push(s2);
            else 
            {
                q.push(s1); 
                q.push(s2);
            }
        }
    }
};