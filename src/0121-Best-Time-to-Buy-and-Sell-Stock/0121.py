class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        result, buy = 0, float('inf')
        for price in prices:
            if buy > price:
                buy = price
            
            if result < price - buy:
                result = price - buy

        return result

        
if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    print(Solution().maxProfit(prices))