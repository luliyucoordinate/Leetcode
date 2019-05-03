class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        nums = sorted([a, b, c])
        d1, d2 = nums[1] - nums[0], nums[2] - nums[1]
        if d1 + d2 == 2:
            return [0, 0]
        return [1 if min(d1, d2) <= 2 else 2, d1 + d2 - 2]