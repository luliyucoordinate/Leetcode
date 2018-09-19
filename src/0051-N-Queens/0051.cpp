#include <iostream>
#include <vector>
using namespace std;


static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<vector<string>> solveNQueens(int n) 
    {
        col = vector<bool>(n, false);
        dia1 = vector<bool>(2*n - 1, false);
        dia2 = vector<bool>(2*n - 1, false);
        vector<int> row;
        putQueen(n, 0, row);
        return result;
    }
private:
    vector<vector<string>> result;
    vector<bool> col, dia1, dia2;

    void putQueen(int n, int index, vector<int>& row)
    {
        if (index == n)
        {
            result.push_back(generateBoard(n, row));
            return;
        }

        for (unsigned int i = 0; i < n; ++i)
        {
            if (!col[i] and !dia1[index + i] and !dia2[index - i + n - 1])
            {
                row.push_back(i);
                col[i] = true;  dia1[index + i] = true;  dia2[index - i + n - 1] = true;
                putQueen(n, index + 1, row);
                col[i] = false; dia1[index + i] = false; dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        }
    }

    vector<string> generateBoard(int n, vector<int>& row)
    {
        vector<string> board(n, string(n, '.'));
        for (unsigned int i = 0; i < n; ++i)
        {
            board[i][row[i]] = 'Q';
        }
        return board;
    }
};

int main()
{
    int n = 4;
    vector<vector<string>> result = Solution().solveNQueens(n);
    for (unsigned int i = 0; i < result.size(); ++i)
    {
        for (unsigned int j = 0; j < n; ++j)
        {
            cout << result[i][j] << endl;
        }
        cout << endl;
    }
}