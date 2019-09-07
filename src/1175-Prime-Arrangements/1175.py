import math, bisect
class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        primes, st, cnt, MOD = [0]*(n + 1), [0]*(n + 1), 0, 10**9 + 7
        for i in range(2, n + 1):
            if not st[i]:
                primes[cnt] = i
                cnt += 1
            j = 0
            while primes[j] <= n//i:
                st[primes[j] * i] = 1
                if i % primes[j] == 0:
                    break
                j += 1
        index = bisect.bisect(primes[:cnt], n)
        return (math.factorial(index)%MOD * math.factorial(n - index)%MOD)%MOD