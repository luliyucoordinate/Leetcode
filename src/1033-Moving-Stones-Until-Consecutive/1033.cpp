static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> numMovesStones(int a, int b, int c) 
    {
        vector<int> s = { a, b, c };
        sort(begin(s), end(s));
        if (s[2] - s[0] == 2) return { 0, 0 };
        return { min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2 };
    }
};