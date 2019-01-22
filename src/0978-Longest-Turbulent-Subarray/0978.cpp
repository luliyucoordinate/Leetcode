static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int maxTurbulenceSize(vector<int>& A) 
    {
        int res = 1, anchor = 0;
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] == A[i-1])
            {
                anchor = i; continue;
            }
            if (i == A.size() - 1 or 
                (A[i] >= A[i-1] and A[i] <= A[i+1]) or 
                (A[i] <= A[i-1] and A[i] >= A[i+1]))
            {
                res = max(res, i - anchor + 1);
                anchor = i;
            }
        }
        return res;
    }
};