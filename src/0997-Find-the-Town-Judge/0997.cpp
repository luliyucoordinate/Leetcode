static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int findJudge(int N, vector<vector<int>>& trust) 
    {
        vector<int> cnt(N + 1);
        for (auto &t : trust) --cnt[t[0]], ++cnt[t[1]];
        for (int i = 1; i <= N; ++i) if (cnt[i] == N - 1) return i;
        return -1;
    }
};