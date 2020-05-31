class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for (auto& it : edges) {
            int i = it[0], j = it[1];
            g[i].emplace_back(j);
            g[j].emplace_back(i);
        }
        
        int vis[n];
        memset(vis, 0, sizeof vis);
        vis[0] = 1;
        return dfs(0, hasApple, vis);
    }
private:
    unordered_map<int, vector<int>> g;
    
    int dfs(int x, vector<bool>& hasApple, int vis[]) {
        int res = 0;
        for (int i : g[x]) {
            if (vis[i]) continue;
            vis[i] = 1;
            
            int cur = dfs(i, hasApple, vis);
            if (cur > 0) res += cur + 2;
            else if (hasApple[i]) res += 2;
        }
        return res;
    }
};