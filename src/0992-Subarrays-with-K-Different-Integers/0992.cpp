static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int subarraysWithKDistinct(vector<int>& A, int K) 
    {
        int res = 0;
        vector<int> m(A.size() + 1);
        for(auto i = 0, j = 0, prefix = 0, cnt = 0; i < A.size(); ++i) 
        {
            if (m[A[i]]++ == 0) ++cnt;
            if (cnt > K) --m[A[j++]], --cnt, prefix = 0;
            while (m[A[j]] > 1) ++prefix, --m[A[j++]];
            if (cnt == K) res += prefix + 1;
        }
        return res;
    }
};