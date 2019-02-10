static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    vector<int> addToArrayForm(vector<int>& A, int K) 
    {
        for (int i = A.size() - 1; i >= 0 and K > 0; --i)
        {
            A[i] += K;
            K = A[i] / 10;
            A[i] %= 10;
        }
        while (K)
        {
            A.insert(A.begin(), K % 10);
            K /= 10;
        }
        return A;
    }
};