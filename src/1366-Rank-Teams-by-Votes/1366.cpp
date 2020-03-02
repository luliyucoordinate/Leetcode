class Solution 
{
public:
    string rankTeams(vector<string>& votes) 
    {
        int n = votes[0].size();
        vector<vector<int>> cnt(26, vector<int>(n + 1, 0));
        for (int i = 0; i < 26; i++) cnt[i][n] = i;
        
        for (const string& vote : votes)
        {
            for (int i = 0; i < n; i++)
            {
                cnt[vote[i] - 'A'][i]--;
            }
        }
        
        sort(votes[0].begin(), votes[0].end(), [&](const char a, const char b) {
            return cnt[a - 'A'] < cnt[b - 'A'];
        });
        return votes[0];
    }
};