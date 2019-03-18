static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int rotatedDigits(int N) 
    {
        unordered_set<int> s1 = {3, 4, 7};
        unordered_set<int> s2 = {2, 5, 6, 9};
        int valid[] = {1,2,3,3,3,4,5,5,6,7};
        int same[] = {1,2,2,2,2,2,2,2,3,3};
        string N_s = to_string(N);
        int res = 0, n = N_s.size();
        bool flag = true;
        
        for (int i = 0; i < n; ++i)
        {
            int v = stoi(N_s.substr(i, 1));
            if (i == n-1)
            {
                res += valid[v];
                if (flag) res -= same[v];
            }
            else
            {
                if (v == 0) continue;
                int t = v - 1;
                res += valid[t]*pow(valid[9], n - i - 1);
                if (flag) res -= same[t]*pow(same[9], n - i - 1);
            }
            if (s2.count(v)) flag = false;
            if (s1.count(v)) return res;
        }
        return res;
    }
};