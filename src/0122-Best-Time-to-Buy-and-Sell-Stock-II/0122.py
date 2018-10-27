class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        result = 0
        for i in range(len(prices)-1):
            if prices[i] < prices[i+1]:
                result += prices[i+1] - prices[i]

        return result

if __name__ == "__main__":
    prices = [1,2,3,4,5]
    print(Solution().maxProfit(prices))