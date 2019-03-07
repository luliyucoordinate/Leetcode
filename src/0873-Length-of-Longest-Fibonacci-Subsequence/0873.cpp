static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int lenLongestFibSubseq(vector<int>& A)
    {
        unordered_set<int> S(A.begin(), A.end());
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = i+1; j < A.size(); ++j)
            {
                int a = A[i], b = A[j];
                long long l = 2;
                if ((res - 2)*b > A.back()) break;
                while (S.count(a + b))
                {
                    b = a + b;
                    a = b - a;
                    ++l;
                }
                res = max(res, l);
            }
        }
        return res > 2 ? res : 0;
    }
};