static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) 
    {
        int a = 0, b = 0, n = A.size();
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != A[0] and B[i] != A[0]) break;
            if (A[i] != A[0]) a++;
            if (B[i] != A[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        a = 0, b = 0;
        
        for (int i = 0; i < n; ++i)
        {
            if (A[i] != B[0] and B[i] != B[0]) break;
            if (A[i] != B[0]) a++;
            if (B[i] != B[0]) b++;
            if (i == n - 1) return min(a, b);
        }
        return -1;
    }
};