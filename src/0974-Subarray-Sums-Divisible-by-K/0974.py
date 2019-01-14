class Solution:
    def subarraysDivByK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        pre_sum, res = 0, 0
        dic = {0:1}
        
        for val in A:
            pre_sum = (pre_sum + val) % K
            if pre_sum in dic:
                res += dic[pre_sum]
            dic[pre_sum] = dic.get(pre_sum, 0) + 1
                
        return res 