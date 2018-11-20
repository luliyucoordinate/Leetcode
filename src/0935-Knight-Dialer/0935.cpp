#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int knightDialer(int N) 
    { 
        vector<long long> result(10, 1);
        vector<long long> mem(10);
        long long mod = 1e9+7;
        for (int i = 1; i < N; i++)
        {
            mem[0] = (result[4] + result[6]) % mod;
            mem[1] = (result[6] + result[8]) % mod;
            mem[2] = (result[7] + result[9]) % mod;
            mem[3] = (result[4] + result[8]) % mod;
            mem[4] = (result[0] + result[3] + result[9]) % mod;
            mem[5] = 0;
            mem[6] = (result[0] + result[1] + result[7]) % mod;
            mem[7] = (result[6] + result[2]) % mod;
            mem[8] = (result[1] + result[3]) % mod;
            mem[9] = (result[2] + result[4]) % mod;
            result = mem;
        }
        return accumulate(result.begin(), result.end(), 0, 
        [=](long long s, long long n) { return int((s + n) % mod);});
    }
};
int main()
{
    int N = 2;
    cout << Solution().knightDialer(N);
    return 0;
}
