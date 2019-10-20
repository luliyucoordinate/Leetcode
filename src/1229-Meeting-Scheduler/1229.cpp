class Solution 
{
public:
    vector<int> minAvailableDuration(vector<vector<int>>& A, vector<vector<int>>& B, int duration) 
    {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        while (i < A.size() and j < B.size())
        {
            int l = max(A[i][0], B[j][0]);
            int r = min(A[i][1], B[j][1]);
            if (l + duration <= r) return {l, l + duration};
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return {};
    }
};