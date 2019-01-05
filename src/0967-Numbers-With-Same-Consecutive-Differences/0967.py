class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """
        if N == 1:
            return list(range(10))
        
        res = list(range(1, 10))
        for _ in range(1, N):
            tmp_res = list()
            for num in res:
                num_s = num % 10
                for i in {num_s - K, num_s + K}:
                    if 0 <= i <= 9:
                        tmp_res.append(num * 10 + i)
            res = tmp_res
            
        return res