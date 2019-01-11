class Solution:
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        p_len = len(prices)
        if k >= p_len//2:
            return self.greedy(prices)
        
        buy, sell = [-prices[0]]*k , [0]*(k+1)
        for p in prices[1:]:
            for i in range(k):
                buy[i] = max(buy[i], sell[i-1]-p)
                sell[i] = max(sell[i], buy[i]+p)
                
        return max(sell)
        
    def greedy(self, prices):
        res = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i-1]:
                res += prices[i] - prices[i-1]
                
        return res