static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxWidthRamp(vector<int>& A) 
    {
        stack<int> s;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i)
        {
            if (s.empty() || A[s.top()] > A[i]) s.push(i);     
        }

        for (int i = n - 1; i > res; --i)
        {
            while (!s.empty() && A[s.top()] <= A[i]) res = max(res, i - s.top()), s.pop();          
        }

        return res;
    }
};