static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int minKBitFlips(vector<int>& A, int K) 
    {
        int cur = 0, res = 0;
        for (int i = 0; i < A.size(); ++i)
        {
            if (i >= K) cur -= A[i -K]/2;
            if (cur & 1 ^ A[i] == 0)
            {
                if (i + K > A.size()) return -1;
                res++; cur++;
                A[i] += 2;
            }
        }
        return res;
    }
};