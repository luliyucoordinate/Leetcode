class Solution 
{
public:
    int maxNumberOfBalloons(string text) 
    {
        unordered_map<char, int> cnt;
        for (char c : text) cnt[c]++;
        string balloon = "balon";
        for (char c : balloon) {
            if (!cnt.count(c)) return 0;
        }
        return min({cnt['b'], cnt['a'], cnt['l']/2, cnt['o']/2, cnt['n']});
    }
};