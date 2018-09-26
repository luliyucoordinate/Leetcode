#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        vector<int> buy(prices.size(), 0), sell(prices.size(), 0), cooldown(prices.size(), 0);
        buy[0] = -prices[0];
        for (unsigned int i = 1; i < prices.size(); ++i)
        {
            cooldown[i] = sell[i - 1];
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
        }
        return max(sell[prices.size() - 1], cooldown[prices.size() - 1]);
    }
};
int main()
{
    vector<int> prices = {1, 2, 4};
    cout << Solution().maxProfit(prices);
    return 0;
}