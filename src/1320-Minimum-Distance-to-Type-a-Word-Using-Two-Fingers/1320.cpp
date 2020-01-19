class Solution 
{
public:
    int minimumDistance(string word) 
    {
        vector<int> dp(26);
        int sum_dis = 0, max_a = 0;
        
        for (int i = 0; i < word.size() - 1; i++)
        {
            int a = word[i] - 65, c = word[i + 1] - 65;
            for (int b = 0; b < 26; b++) 
                dp[a] = max(dp[a], dp[b] + dis(a, c) - dis(b, c));
            max_a = max(max_a, dp[a]);
            sum_dis += dis(a, c);
        }
        
        return sum_dis - max_a;
    }
private:
    int dis(int a, int b)
    {
        return abs(a/6 - b/6) + abs(a%6 - b%6);
    }
};  