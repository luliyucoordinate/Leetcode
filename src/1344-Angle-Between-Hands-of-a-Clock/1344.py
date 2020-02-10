class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        t = abs((hour*30 + minutes/2) - minutes*6)
        return min(t, 360 - t)