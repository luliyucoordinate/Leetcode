class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def get_divisors(x):
            res, cnt, i = 0, 0, 1
            while i * i <= x:
                if x % i == 0:
                    res += i
                    cnt += 1
                    if i * i != x: 
                        res += x // i
                        cnt += 1
                    if cnt > 4: return 0
                i += 1
            return 0 if cnt < 4 else res
        
        return sum(get_divisors(v) for v in nums)