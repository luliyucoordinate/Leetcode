class Solution:
    def numOfBurgers(self, t: int, c: int) -> List[int]:
        return [t // 2 - c, c * 2 - t // 2] if t % 2 == 0 and c * 2 <= t <= c * 4 else []