class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        prem = 1 << (n - 1)
        if prem * 3 < k: return ""
        
        k -= 1
        s = chr(97 + k // prem)
        while prem > 1:
            k %= prem
            prem >>= 1
            s += chr(97 + int(s[-1] == 'a')) if k // prem == 0 else chr(98 + int(s[-1] != 'c'))
        return s