static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int longestConsecutive(vector<int> &num) 
    {
        unordered_set<int> mem(num.begin(),num.end());
        int res = 0;
        for (int x : mem)
        {
            if (mem.count(x - 1)) continue;
            int y = x + 1;
            while (mem.count(y)) y++;
            res = max(res, y - x);
        }
        return res;
    }
};