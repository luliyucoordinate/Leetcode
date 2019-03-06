static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0, di = 0;

        set<pair<int, int>> obstacleSet;
        for (auto& ob: obstacles) obstacleSet.insert(make_pair(ob[0], ob[1]));

        int res = 0;
        for (int cmd: commands) 
        {
            if (cmd == -2) di = (di + 3) % 4;
            else if (cmd == -1) di = (di + 1) % 4;
            else 
            {
                for (int k = 0; k < cmd; ++k) 
                {
                    x += d[di][0];
                    y += d[di][1];
                    if (obstacleSet.count(make_pair(x, y))) 
                    {
                        x -= d[di][0];
                        y -= d[di][1];
                    }
                }
            }
            res = max(res, x*x + y*y);
        }

        return res;
    }
};