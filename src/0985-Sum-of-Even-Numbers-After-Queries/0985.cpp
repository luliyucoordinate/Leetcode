#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) 
    {
        int sum_all = 0;
        for (int a : A) 
        {
            if ((a & 1) == 0) sum_all += a;
        }
        
        vector<int> res;
        for (int i = 0; i < queries.size(); ++i)
        {
            int val = queries[i][0], index = queries[i][1];
            if ((A[index] & 1) == 0) sum_all -= A[index];
            A[index] += val;
            if ((A[index] & 1) == 0) sum_all += A[index];
            res.push_back(sum_all);
        }
        return res;
    }
};