class Solution 
{
public:
    bool canReach(vector<int>& arr, int start) 
    {
        queue<int> q;
        q.push(start);
        int vis[arr.size()] = {};
        vis[start] = 1;
        
        while (!q.empty())
        {
            int cur = q.front(); q.pop();
            if (arr[cur] == 0) return true;
            
            vis[cur] = true;
            int a = cur + arr[cur], b = cur - arr[cur];
            if (a >= 0 && a < arr.size() && !vis[a]) q.push(a);
            if (b >= 0 && b < arr.size() && !vis[b]) q.push(b);
        }
        return false;
    }
};