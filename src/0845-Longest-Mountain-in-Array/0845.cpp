static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int longestMountain(vector<int>& A) 
    {
        int res = 0, l = 0, r = 0, m = 0, n = A.size();
        while (l < n)
        {
            while (m < n - 1 and A[m] < A[m+1]) ++m;

            if (m == l)
            {
                ++l;
                m = r = l;
                continue;
            }
            r = m;
            while (r < n - 1 and A[r] > A[r+1]) ++r;
            
            if (m != r) res = max(res, r - l + 1);
            l = m = r;
        }
        return res;
    }
};