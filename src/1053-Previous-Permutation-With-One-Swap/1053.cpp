static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> prevPermOpt1(vector<int>& A) 
    {
        int i = A.size()-1, j = i;
        while (i > 0 and A[i] >= A[i-1]) --i;
        --i;
        if (i >= 0) 
        {
            while (j >= i and A[i] <= A[j]) --j;
            while (j >=i and A[j] == A[j-1]) --j;
            swap(A[i], A[j]);
        }
        return A;
    }
};