class Solution 
{
public:
    int twoSumLessThanK(vector<int>& A, int K) 
    {
        int res = -1, n = A.size();
        sort(A.begin(), A.end());
        int l = 0, r = n - 1;
        while (l < r)
        {
            int t = A[l] + A[r];
            if (t >= K) r--;
            else 
            {
                res = max(res, t);
                l++;
            }
        }
        return res;
    }
};