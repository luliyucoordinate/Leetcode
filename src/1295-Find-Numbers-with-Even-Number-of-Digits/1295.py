class Solution:
    def findNumbers(self, nums: List[int]) -> int:
        res = 0
        for n in nums:
            x = int(math.log(n, 10) + 1)
            if x % 2 == 0:
                res += 1
        return res