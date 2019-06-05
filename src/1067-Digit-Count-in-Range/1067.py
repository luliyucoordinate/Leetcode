class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        def digits(k, n):
            base, cnt = 1, 0
            while n // base:
                cur = n//base%10
                l = n%base
                r = n//(base*10)
                if cur == k:
                    if k == 0:
                        cnt += (r - 1) * base + l + 1
                    else:
                        cnt += 1 + base * r + l
                elif cur < k:
                    cnt += base * r
                else:
                    if k == 0:
                        cnt += base * r 
                    else:
                        cnt += base * (r + 1)
                base *= 10
            return cnt
        
        return digits(d, high) - digits(d, low-1)