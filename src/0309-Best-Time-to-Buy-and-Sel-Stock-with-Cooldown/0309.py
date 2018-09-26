class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """  
        if not prices:
            return 0

        len_prices = len(prices)
        buy, sell, cooldown = [0]*len_prices, [0]*len_prices, [0]*len_prices
        buy[0] = -prices[0]
        for i in range(1, len_prices):
            cooldown[i] = sell[i-1]
            sell[i] = max(sell[i-1], buy[i-1] + prices[i])
            buy[i] = max(buy[i-1], cooldown[i-1] - prices[i])

        return max(sell[len_prices - 1], cooldown[len_prices - 1])  
  

if __name__ == '__main__':
    prices = [1,2,4]
    print(Solution().maxProfit(prices))