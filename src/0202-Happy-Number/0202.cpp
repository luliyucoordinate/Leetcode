#include <iostream>
#include <unordered_set>
using namespace std;
static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    bool isHappy(int n) 
    {
        unordered_set<int> sum_set;
        while (n != 1)
        {
            int num_sum = 0;
            while (n > 0)
            {
                int k = n % 10;
                num_sum += k*k;
                n /= 10;
            }
            if (sum_set.count(num_sum) >= 1) return false;
            sum_set.insert(num_sum);
            n = num_sum;
        }
        return true;
    }
};
int main()
{
    int n = 19;
    cout << Solution().isHappy(n) << endl;
    return 0;
}