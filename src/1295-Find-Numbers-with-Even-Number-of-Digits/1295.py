class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        return sum(map(lambda n: len(str(n)) % 2 == 0, nums))  