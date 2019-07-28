class Solution 
{
public:
    int largestUniqueNumber(vector<int>& A) 
    {
        sort(A.begin(), A.end());
        while (A.size() > 1 and A.back() == A[A.size()-2])
        {
            int bk = A.back();
            while (!A.empty() and A.back() == bk) A.pop_back();
        }
        if (A.empty()) return -1;
        return A.back();
    }
};