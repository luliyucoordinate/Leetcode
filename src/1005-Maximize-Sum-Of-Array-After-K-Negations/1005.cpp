static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int largestSumAfterKNegations(vector<int>& A, int K) 
    {
        sort(A.begin(), A.end());
        int i = 0;
        while (i < A.size() and i < K and A[i] < 0) A[i]=-A[i], ++i;
        return accumulate(A.begin(), A.end(), 0) - (K - i)%2 * *min_element(A.begin(), A.end())*2;
    }
};