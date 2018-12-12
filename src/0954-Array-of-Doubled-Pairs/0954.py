from collections import Counter
class Solution:
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        A_dict = Counter(A)
        
        for x in sorted(A_dict, key=lambda x: abs(x)):
            if A_dict[x] > A_dict[2*x]:
                return False
            
            A_dict[2*x] -= A_dict[x]
        return True