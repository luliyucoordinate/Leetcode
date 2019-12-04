class Solution 
{
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        int score[2][8] = {}, p = 0;
        for (auto& it : moves)
        {
            score[p][it[0]]++, score[p][it[1] + 3]++;
            score[p][6] += (it[0] == it[1]);
            score[p][7] += (it[0] + it[1] == 2);
            for (int x : score[p])
                if (x == 3) return p == 0 ? "A" : "B";
            p ^= 1;
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
};