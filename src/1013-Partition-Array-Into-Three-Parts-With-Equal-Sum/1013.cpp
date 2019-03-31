static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool canThreePartsEqualSum(vector<int>& A) 
    {
        int total = accumulate(A.begin(), A.end(), 0); 
        if (total % 3 != 0) return false;
        int p = total / 3, res = 0;
        for (int i = 0, sum = 0; i < A.size(); ++i) 
        {
            sum += A[i];
            if (sum == p) ++res, sum = 0;
        }
        return res >= 3;
    }
};