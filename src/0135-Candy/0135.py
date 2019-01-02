class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        rat_len = len(ratings)
        res = [1]*rat_len
        for i in range(1, rat_len):
            if ratings[i] > ratings[i-1]:
                res[i] = res[i-1] + 1
                
        for i in range(rat_len-1, 0, -1):
            if ratings[i-1] > ratings[i] and res[i-1] <= res[i]:
                res[i-1] = res[i] + 1
              
        return sum(res)