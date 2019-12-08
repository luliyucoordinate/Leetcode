class Solution 
{
public:
    int minFlips(vector<vector<int>>& mat) 
    {
        int start = 0, r = mat.size(), c = mat[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++) start |= mat[i][j] << i * c + j;
        }

        queue<int> q;
        q.push(start);
        unordered_set<int> seen;
        for (int step = 0; !q.empty(); step++)
        {
            for (int qs = q.size(); qs > 0; qs--)
            {
                int cur = q.front(); q.pop();
                if (!cur) return step;
                for (int i = 0; i < r; i++) 
                {
                    for (int j = 0; j < c; j++)
                    {
                        int ne = cur;
                        for (int k = 0; k < 5; k++)
                        {
                            int x = d[k] + i, y = d[k+1] + j;
                            if (x >= 0 && x < r && y >= 0 && y < c)
                                ne ^= (1 << x * c + y);
                        }
                        if (!seen.count(ne))
                        {
                            seen.insert(ne);
                            q.push(ne);
                        }
                    }
                }
            }
        }
        return -1;
    }
private:
    int d[6] = {0, 0, 1, 0, -1, 0};
};