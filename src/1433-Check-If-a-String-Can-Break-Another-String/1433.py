class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        d1 = collections.Counter(s1)
        d2 = collections.Counter(s2)
        
        def check(a1, a2):
            s = 0
            for c in string.ascii_lowercase:
                s += a1[c] - a2[c]
                if s < 0:
                    return False
            return True
        return check(d1, d2) or check(d2, d1)