static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) 
    {
        string N_s = to_string(N+1);
        int n = N_s.size(), res = 0;
        for (int i = 1; i < n; ++i)
        {
            res += pow(D.size(), i);
        }
        
        int i = 0;
        unordered_set<string> Dset(D.begin(), D.end());
        for (; i < n; ++i)
        {
            int tmp = count_if(D.begin(), D.end(), [&](const string d){return d[0] < N_s[i];});
            res += tmp*pow(D.size(), n - i - 1);
            if (!Dset.count(string(1, N_s[i]))) break;
        }

        return res;
    }
};