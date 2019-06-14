class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        res = list()
        carry, l1, l2 = 0, len(arr1), len(arr2)
        while carry or l1 or l2:
            if l1:
                l1 -= 1
                carry += arr1[l1]
            if l2:
                l2 -= 1
                carry += arr2[l2]
            res.append(carry & 1)
            carry = -(carry >> 1)
            
        while len(res) > 1 and res[-1] == 0:
            res.pop()
        
        return res[::-1]