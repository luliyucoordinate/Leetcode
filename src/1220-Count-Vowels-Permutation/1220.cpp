class Solution 
{
public:
    int countVowelPermutation(int n) 
    {
        unsigned int mod = 1e9 + 7, a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 1; k < n; k++)
        {
            auto ao = a; a = (e + i + u)%mod; 
            auto eo = e; e = (ao + i)%mod;
            auto io = i; i = (eo + o)%mod;
            auto oo = o; o = io;
            u = (io + oo)%mod;
        }
        return (a + e + i + o + u)% mod;
    }
};