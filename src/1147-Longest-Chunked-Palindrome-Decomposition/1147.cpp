class Solution 
{
public:
    int longestDecomposition(string text) 
    {
        int n = text.size();
        for (int i = 1; i <= n/2; ++i)
        {
            if (text.substr(0,i) == text.substr(n-i))
                return 2 + longestDecomposition(text.substr(i,n-2*i));
        }
        return n == 0 ? 0 : 1;
    }
};