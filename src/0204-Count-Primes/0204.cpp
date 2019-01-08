#include <deque>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int countPrimes(int n) 
    {
        if (n <= 2) return 0;
        int m = n/2, count = m, u = sqrt(n)/2;
        deque<bool> flag(m, 0);

        for (int i = 1; i <= u; i++)
        {
            if (!flag[i])
            {
                for (int k = (i+ 1)*2*i; k < m; k += i*2 + 1)
                {
                    if (!flag[k])
                    {
                        flag[k] = true;
                        count--;
                    }   
                }
            }
        }
            
        return count;
    }
};