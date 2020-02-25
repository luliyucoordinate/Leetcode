class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        for i in range(int((num + 2)**0.5), 0, -1):
            if (num + 1) % i == 0:
                return [i, (num + 1) // i]
            if (num + 2) % i == 0:
                return [i, (num + 2) // i]

"""
import functools, operator, itertools
class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        
        def get_factor(x):
            res, i = [1], 2
            while i * i <= x:
                while x % i == 0:
                    x //= i
                    res.append(i)
                i += 1
            if x > 1:
                res.append(x)
            return res
        
        t1, t2 = get_factor(num + 1), get_factor(num + 2)
        
        res = [0, float("inf")]
        def get_closest_divisors(arr, x):
            nonlocal res
            n = len(arr)
            for i in range(1, n//2 + 1):
                for j in itertools.combinations(arr, i):
                    t = functools.reduce(operator.mul, j)
                    if abs(t - x // t) < abs(res[0] - res[1]):
                        res = [t, x// t]
        
        get_closest_divisors(t1, num + 1)
        get_closest_divisors(t2, num + 2)
        return res
"""