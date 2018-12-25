static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        N = N % 14;
        if (N == 0) N = 14;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 1; j < 7; ++j)
            {
                if ((cells[j-1] & 1) == (cells[j+1] & 1))
                {
                    cells[j] = cells[j] & 1 ? 3 : 2;
                }
            }
            for (int j = 0; j < 8; ++j)
            {
                cells[j] >>= 1;
            }       
        }
        return cells;
    }
};