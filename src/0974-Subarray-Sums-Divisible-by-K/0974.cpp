#include <unordered_map>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        int pre_sum = 0, res = 0;
        unordered_map<int, int> dic = {{0, 1}};
        for (int a : A)
        {
            pre_sum = (pre_sum + a) % K;
            if (pre_sum < 0) pre_sum += K;
            res += dic[pre_sum];
            dic[pre_sum]++;
        }
        return res;
    }
};