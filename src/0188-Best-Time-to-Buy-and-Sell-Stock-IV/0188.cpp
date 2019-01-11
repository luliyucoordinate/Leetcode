#include <vector>
#include <algorithm>
using namespace std;

static int x = []() {std::ios::sync_with_stdio(false); cin.tie(0); return 0; }();
class Solution 
{
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        if (k >= prices.size() / 2) return greedy(prices);
        vector<int> buys(k, -prices[0]), sells(k + 1, 0);
        for (int i = 1; i < prices.size(); ++i)
        {
            for (int j = 0; j < k; ++j) 
            {
                buys[j] = max(buys[j], sells[j - 1] - prices[i]);
                sells[j] = max(sells[j], buys[j] + prices[i]);  
            }
        }

        return *max_element(sells.begin(), sells.end());
    }
private:
    int greedy(vector<int>& p) 
    {
        int res = 0;
        for (int i = 1; i < p.size(); ++i) res += max(0, p[i] - p[i - 1]);
        return res;
    }
};