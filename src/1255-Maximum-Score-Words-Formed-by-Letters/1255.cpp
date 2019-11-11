class Solution 
{
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        n = words.size();
        cnt = vector<int>(26, 0);
        for (char c : letters) cnt[c - 97]++;
        return dfs(0, words, score);
    }
private:
    vector<int> cnt;
    int n;
    
    int dfs(int i, vector<string>& words, vector<int>& score)
    {
        if (i == n) return 0;
        int res = max(0, dfs(i + 1, words, score)), tmp = 0, val = 1;
        for (char c : words[i])
        {
            int t = c - 97;
            cnt[t]--;
            tmp += score[t];
            if (cnt[t] < 0) val = 0;
        }
        if (val) res = max(res, dfs(i + 1, words, score) + tmp);
        for (char c : words[i]) cnt[c - 97]++;
        return res;
    }
};