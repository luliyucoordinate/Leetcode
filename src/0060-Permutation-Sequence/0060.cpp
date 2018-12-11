static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        string res;
        int fac = 1;
        for (int i = 1; i <= n; ++i) 
        {
            res.push_back('0' + i);
            fac *= i;
        }
        --k;
        for (auto first = res.begin(); n > 0; --n, ++first) 
        {
            fac /= n; 
            auto index = first + k / fac;
            rotate(first, index, index+1);
            k %= fac;
        }
        return res;
    }
};