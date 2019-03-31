static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numDupDigitsAtMostN(int N) 
    {
        vector<int> L;
        for (int i = N+1; i > 0; i /= 10)
        {
            L.insert(L.begin(), i%10);
        }

        int res = 0, n = L.size();
        for (int i = 1; i < n; ++i)
            res += 9 * A(9, i-1);
        
        unordered_set<int> seen;
        for (int i = 0; i < n; ++i)
        {
            int cnt = 0;
            int j = i > 0 ? 0 : 1;
            for (; j < L[i]; ++j) cnt += static_cast<int>(!seen.count(j));
            res += cnt*A(9 - i, n - i - 1);
            if (seen.count(L[i])) break;
            seen.insert(L[i]);
        }
        return N - res;
    }
    
private:
    int A(int m, int n)
    {
        return n == 0 ? 1 : A(m, n - 1)*(m - n + 1);
    }
};