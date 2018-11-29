#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        for (int i = 0; i < stones.size(); ++i)
            uni(stones[i][0], ~stones[i][1]);
        return stones.size() - islands;
    }
private:
    unordered_map<int, int> f;
    int islands = 0;

    int find(int x) 
    {
        if (!f.count(x)) f[x] = x, islands++;
        if (x != f[x]) f[x] = find(f[x]);
        return f[x];
    }

    void uni(int x, int y) 
    {
        x = find(x), y = find(y);
        if (x != y) f[x] = y, islands--;
    }
};