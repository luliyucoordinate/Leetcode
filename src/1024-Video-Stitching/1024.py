class Solution:
    def videoStitching(self, clips: List[List[int]], T: int) -> int:
        pre, cur, step = -1, 0, 0
        for i, j in sorted(clips):
            if cur >= T or i > cur:
                break
            elif pre < i <= cur:
                step, pre = step + 1, cur
            cur = max(cur, j)
        return step if cur >= T else -1