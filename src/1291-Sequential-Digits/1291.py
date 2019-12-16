class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        res = []
        for x in range(1, 9):
            while x <= high:
                r = x % 10
                if r == 0:
                    break
                    
                if x >= low:
                    res.append(x)
                x = x * 10 + r + 1
        return sorted(res)