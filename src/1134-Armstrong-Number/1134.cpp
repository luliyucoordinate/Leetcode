class Solution 
{
public:
    bool isArmstrong(int N) 
    {
        string Nstr = to_string(N);
        int n = Nstr.size(), res = 0;
        for (auto c : Nstr) res += pow(c - '0', n);
        return res == N;
    }
};