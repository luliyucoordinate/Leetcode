class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = 1 if x >= 0 else -1
        x *= neg
        num = 0
        while x:
            num = num*10 + x%10
            x //= 10
        if num > (2**31) - 1 or num < -1*(2**31):
            return 0
        return num*neg