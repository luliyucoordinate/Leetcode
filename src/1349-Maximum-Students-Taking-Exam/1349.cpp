class Solution 
{
public:
    int maxStudents(vector<vector<char>>& seats) 
    {
        r = seats.size(), c = seats[0].size();
        match = vector<vector<int>>(r * c);
        int res = 0, cnt = 0;
        
        int vis[r * c] = {};
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j += 2)
            {
                if (seats[i][j] != '.') continue;
                memset(vis, 0, sizeof vis);
                vector<int> node = {i, j};
                if (find(node, vis, seats)) res++;
            }
        }
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (seats[i][j] == '.') cnt++;
        return cnt - res;
    }
private:
    int d[6][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 1}, {0, 1}, {1, 1}};
    int r, c;
    vector<vector<int>> match;
    
    bool find(vector<int>& node, int* vis, vector<vector<char>>& seats)
    {
        for (auto& it : d)
        {
            int nx = it[0] + node[0], ny = it[1] + node[1];
            if (nx >= 0 && nx < r && ny >= 0&& ny < c && !vis[nx * c + ny] && seats[nx][ny] == '.')
            {
                vis[nx * c + ny] = 1;
                if (match[nx * c + ny].empty() || find(match[nx * c + ny], vis, seats))
                {
                    match[nx * c + ny] = node;
                    return true;
                }
            }
        }
        return false;
    }
};