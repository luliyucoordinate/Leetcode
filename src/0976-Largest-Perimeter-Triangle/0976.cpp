#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int largestPerimeter(vector<int>& A) 
    {
        sort(A.begin(), A.end(), greater<int>());
        for (int i = 0; i < A.size()-2; ++i)
        {
            if (A[i+1] + A[i+2] > A[i]) return A[i] + A[i+1] + A[i+2];
        }
        return 0;
    }
};