class Solution 
{
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) 
    {
        int n = books.size();
        vector<int> mem(n + 1, 1000*1000);
        mem[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            int w = 0, h = 0;
            for (int j = i - 1; j >= 0; --j) 
            {
                w += books[j][0];
                h = max(h, books[j][1]);
                if (w > shelf_width) break;
                mem[i] = min(mem[i], mem[j] + h);
            }
        }
        return mem.back();
    }
};