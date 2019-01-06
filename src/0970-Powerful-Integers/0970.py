import math
class Solution:
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        i = 1 if x == 1 else int(math.log(bound, x)) + 1
        j = 1 if y == 1 else int(math.log(bound, y)) + 1
        res = set()

        for m in range(i):
            for n in range(j):
                tmp = x**m + y**n
                if tmp <= bound:
                    res.add(tmp)
                    
        return list(res)