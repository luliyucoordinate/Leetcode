class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        ret = sum([int(i) for i in str(min(A))])
        return 0 if ret & 1 else 1