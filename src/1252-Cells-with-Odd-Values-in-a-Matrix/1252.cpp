class Solution 
{
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        int row[n] = {}, col[m] = {}, rowCnt = 0, colCnt = 0;
        for (auto& it : indices)
        {
            row[it[0]] ^= 1;
            col[it[1]] ^= 1;
            rowCnt += row[it[0]] ? 1 : -1;
            colCnt += col[it[1]] ? 1 : -1;
        }
        return m * rowCnt + n * colCnt  - rowCnt * colCnt * 2;
    }
};