class Solution:
    def maximumSum(self, arr: List[int]) -> int:
        deleted = notDeleted = 0
        res = float('-inf')
        for i, a in enumerate(arr):
            deleted = max(deleted + a, a)
            if i > 0:
                deleted = max(deleted, notDeleted)
            notDeleted = max(notDeleted + a, a)
            res = max(res, deleted)
        return res