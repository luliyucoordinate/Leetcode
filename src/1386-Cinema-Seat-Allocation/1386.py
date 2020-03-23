class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        cnt = collections.defaultdict(int)
        for i, j in reservedSeats:
            cnt[i] |= 1 << (j - 1)
            
        res = 0
        q1 = int('0111111110', 2)
        q2 = int('0111100000', 2)
        q3 = int('0000011110', 2)
        q4 = int('0001111000', 2)
        for v in cnt.values():
            print(v)
            if v & q1 == 0:
                res += 2
            elif v & q2 == 0 or v & q3 == 0 or v & q4 == 0:
                res += 1
        return res + (n - len(cnt)) * 2