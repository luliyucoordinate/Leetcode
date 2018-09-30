#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <math.h>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        sort(coins.begin(), coins.end(), greater<int>());
        result = amount + 1;
        countCoins(coins, 0, amount, 0);
        return result > amount ? -1 : result;
    }
private:
    int result;
    void countCoins(vector<int>& coins, int index, int target, int count)
    {
        if (count + ceil(target/coins[index]) >= result) return;
        if (target % coins[index] == 0) 
        {
            result = count + int(target / coins[index]);
            return;
        }

        if (index == coins.size() - 1) return;

        for (int i = int(target/coins[index]); i >= 0; --i)
            countCoins(coins, index + 1, target - coins[index]*i, count + i);
    }
};
int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << Solution().coinChange(coins, amount);
    return 0;
}