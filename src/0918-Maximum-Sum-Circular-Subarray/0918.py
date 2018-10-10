class Solution:
    def maxSubarraySumCircular(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        cur_max = 0
        result_max = 0

        for num in A:
            cur_max += num
            if cur_max <= 0:
                cur_max = 0
            if result_max < cur_max:
                result_max = cur_max
        
        if result_max == 0:
            return max(A)
        
        cur_min = 0
        result_min = 0
        
        for num in A:
            cur_min += num
            if cur_min >= 0:
                cur_min = 0
            if result_min > cur_min:
                result_min = cur_min
       
        return max(result_max, sum(A) - result_min)
        

if __name__ == "__main__":
    A = [-2, -3, -1]
    print(Solution().maxSubarraySumCircular(A))