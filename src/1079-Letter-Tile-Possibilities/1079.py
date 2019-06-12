from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        cnts = Counter(tiles)
        res = 0
        
        def dfs():
            nonlocal res
            for c, v in cnts.items():
                if v > 0:
                    cnts[c] -= 1
                    res += 1
                    dfs()
                    cnts[c] += 1
        dfs()
        return res