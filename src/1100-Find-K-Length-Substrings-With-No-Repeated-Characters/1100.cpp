class Solution 
{
public:
    int numKLenSubstrNoRepeats(string S, int K) 
    {
        int res = 0, low = -1;
        unordered_map<char, int> usedChar;
        for (int i = 0; i < S.size(); ++i)
        {
            if (usedChar.count(S[i]) and usedChar[S[i]] >= low) low = usedChar[S[i]];
            if (i - low >= K) res++;
            usedChar[S[i]] = i;
        }
        return res;
    }
};