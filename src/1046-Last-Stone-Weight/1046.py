import bisect
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones.sort()
        while len(stones) > 1:
            t1 = stones.pop()
            t2 = stones.pop()
            if t1 != t2:
                bisect.insort_left(stones, t1 - t2)
        return stones[0] if stones else 0