static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numRookCaptures(vector<vector<char>>& board) 
    {
        vector<int> R(2, 0);
        for (int i = 0; i < 8; ++i)
        {
            for (int j = 0; j < 8; ++j)
            {
                if (board[i][j] == 'R')
                {
                    R[0] = i; R[1] = j; break;
                }
            }
        }
        
        int res = 0;
        vector<vector<int>> d = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for (auto& it : d)
        {
            int nx = it[0] + R[0];
            int ny = it[1] + R[1];
            while (nx >= 0 and ny >= 0 and ny < 8 and nx < 8)
            {
                if (board[nx][ny] == 'p') 
                {
                    res++; break;
                }
                if (board[nx][ny] == 'B') break;
                nx += it[0]; ny += it[1];
            }
        }
        return res;
    }
};