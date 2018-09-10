class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        sum_set = set()
        while n != 1:
            num_sum = 0
            while n > 0:
                k = n % 10
                num_sum += k**2
                n //= 10

            if num_sum in sum_set:
                return False
            else:
                sum_set.add(num_sum)
            
            n = num_sum

        return True

        
if __name__ == "__main__":
    n = 19
    print(Solution().isHappy(n))