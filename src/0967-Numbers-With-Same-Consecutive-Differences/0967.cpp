#include <vector>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    vector<int> numsSameConsecDiff(int N, int K) 
    {
        if (N == 1) return {0,1,2,3,4,5,6,7,8,9};
        vector<int> res = {1,2,3,4,5,6,7,8,9};
        for (int i = 1; i < N; ++i)
        {
            vector<int> tmp_res;
            for (int num : res)
            {
                int tmp_m = num % 10 - K;
                int tmp_p = num % 10 + K;
                if (tmp_m >=0) tmp_res.push_back(num*10 + tmp_m);
                if (tmp_p < 10 and K > 0) tmp_res.push_back(num*10 + tmp_p);
            }
            res = tmp_res;
        }
        return res;
    }
};