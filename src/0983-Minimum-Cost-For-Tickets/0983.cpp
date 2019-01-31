static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) 
    {
        unordered_set<int> travel(begin(days), end(days));
        int dp[31] = {};
        for (int i = 1; i <= days.back(); ++i) 
        {
            if (travel.find(i) == travel.end()) dp[i % 31] = dp[(i - 1) % 31];
            else dp[i % 31] = min({ dp[(i - 1) % 31] + costs[0],
            dp[max(0, i - 7) % 31] + costs[1], dp[max(0, i - 30) % 31] + costs[2] });
        }
        return dp[days.back() % 31];
    }
};