class Solution:
    def maxSubarraySumCircular(self, a):
        """
        :type A: List[int]
        :rtype: int
        """      
        def kadane(nums): 
            cur, result = 0, 0
            for num in nums: 
                cur += num 
                if cur < 0: 
                    cur = 0
                if result < cur: 
                    result = cur 
            return result 
        
        max_a = max(a)
        if max_a < 0:
            return max_a

        len_a = len(a) 
        result1 = kadane(a) 
        result2 = 0
        for i in range(len_a): 
            result2 += a[i] 
            a[i] = -a[i] 

        result2 += kadane(a) 

        return max(result1, result2)
        

if __name__ == "__main__":
    A = [-2, -3, -1]
    print(Solution().maxSubarraySumCircular(A))