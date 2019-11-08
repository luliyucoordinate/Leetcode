class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        res = i = best = 0
        for w in sorted(worker):
            while i < len(jobs) and w >= jobs[i][0]:
                best = max(jobs[i][1], best)
                i += 1
            res += best
        return res