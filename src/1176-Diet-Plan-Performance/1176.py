class Solution:
    def dietPlanPerformance(self, calories: List[int], k: int, lower: int, upper: int) -> int:
        T = sum(calories[:k])
        res = (T > upper) - (T < lower)
        for i in range(k, len(calories)):
            T += calories[i] - calories[i - k]
            res += (T > upper) - (T < lower)
        return res