class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res, i, m, k = [], 0, len(target), 1
        while i < m:
            if target[i] == k:
                res.append("Push")
            else:
                i -= 1
                res.extend(["Push", "Pop"])
            i += 1
            k += 1
        return res