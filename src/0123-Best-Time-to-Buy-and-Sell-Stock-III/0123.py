class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
            return 0

        len_prices = len(prices)
        buy1, sell1, buy2, sell2 = -prices[0], 0, -prices[0], 0

        for i in range(1, len_prices):
            buy1 = max(buy1, -prices[i])
            sell1 = max(sell1, buy1 + prices[i])
            buy2 = max(buy2, sell1 - prices[i])
            sell2 = max(sell2, buy2 + prices[i])


        return max(0, sell1, sell2)


if __name__ == "__main__":
    prices = [1,2,3,4,5]
    print(Solution().maxProfit(prices))