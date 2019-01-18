#include <vector>
using namespace std;

static int x = [](){std::ios::sync_with_stdio(false);cin.tie(0);return 0;}();
class Solution 
{
public:
    int sumSubarrayMins(vector<int>& A) 
    {
        A.insert(A.begin(), 0); A.push_back(0);
        int res = 0, mod = 1e9 + 7;
        vector<int> s;
        
        for (int i = 0; i < A.size(); ++i)
        {
            while (!s.empty() and A[s.back()] > A[i])
            {
                int j = s.back(); s.pop_back();
                int k = s.back();
                res = (res + A[j]*(i - j) * (j - k))%mod;
            }
            s.push_back(i);
        }
        return res;
    }
};