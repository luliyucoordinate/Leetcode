#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int numMusicPlaylists(int N, int L, int K) 
    {
        long mem[N+1][L+1], mod = 1e9+7;
        for (unsigned int i = K + 1; i <= N; ++i)
        {
            for (unsigned int j = i; j <= L; ++j)
            {
                if (i == j or i == K + 1) 
                {
                    mem[i][j] = factorial(i);
                }
                else
                {
                    mem[i][j] = (mem[i-1][j-1]*i + mem[i][j-1]*(i - K))%mod;
                }
            }
        }
        return (int)mem[N][L];
    }
private:
    long factorial(int n)
    {
        return n > 1 ? factorial(n - 1)*n%(long)(1e9+7) : 1;
    }
};

int main()
{
    int N = 2, L = 3, K = 1;
    cout << Solution().numMusicPlaylists(N, L, K);
    return 0;
}