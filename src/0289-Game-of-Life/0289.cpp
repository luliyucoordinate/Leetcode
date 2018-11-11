#include <iostream>
#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int r = board.size(), c = board[0].size();
        const vector<vector<int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        for (unsigned int i = 0; i < r; ++i)
        {
            for (unsigned int j = 0; j < c; ++j)
            {
                int lives = 0;
                for (const auto& neigh : neighbors)
                {
                    int new_i = i + neigh[0], new_j =j + neigh[1];
                    if (new_i >= 0 and new_i < r and new_j >= 0 and new_j < c)
                    {
                        lives += board[new_i][new_j] & 1;
                    }
                }
                if (board[i][j] and lives >= 2 and lives < 4) board[i][j] = 3;
                if (!board[i][j] and lives == 3) board[i][j] = 2;
            }
        }
        for (unsigned int i = 0; i < r; ++i)
        {
            for (unsigned int j = 0; j < c; ++j)
            {
                board[i][j] >>= 1;
            }
        }
    }
};
int main(int argc, char const *argv[])
{
    return 0;
}
