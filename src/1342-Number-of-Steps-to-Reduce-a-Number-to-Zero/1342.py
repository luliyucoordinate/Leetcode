class Solution:
    def numberOfSteps (self, num: int) -> int:
        return 0 if not num else 1 + self.numberOfSteps(num >> 1 if num % 2 == 0 else num - 1)