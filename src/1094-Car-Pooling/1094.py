class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        if not trips:
            return 0
        tmp = sorted(x for v, i, j in trips for x in [[i, v], [j, -v]])
        
        n = 0
        for _, v in tmp:
            n += v
            if n > capacity:
                return False
        return True