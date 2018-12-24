static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int repeatedNTimes(vector<int>& A) 
    {
        for (int i = 0; i < A.size()-1; ++i)
        {
            if ((A[0] == *(A.rbegin())) or (A[0] == *(A.rbegin() + 1))) return A[0];
            else if (A[1] == *(A.rbegin())) return A[1];
            else if (A[i] == A[i+1] or (i < A.size() -2 and A[i] == A[i + 2])) return A[i];
        }
    }
};