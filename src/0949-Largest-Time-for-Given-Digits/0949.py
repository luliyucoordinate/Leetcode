from itertools import permutations
class Solution:
    def largestTimeFromDigits(self, A):
        """
        :type A: List[int]
        :rtype: str
        """
        A_per = permutations(A)
        res = ''
        for a in A_per:
            pre = a[0]*10 + a[1]
            pos = a[2]*10 + a[3]
            if pre > 23 or pos > 59:
                continue
            
            str_pre, str_pos = str(pre), str(pos)
            if a[0] == 0:
                str_pre = '0' + str_pre
                
            if a[2] == 0:
                str_pos = '0' + str_pos

            cur = str_pre + ':' + str_pos
            res = max(cur, res)
            
        return res