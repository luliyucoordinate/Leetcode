class Solution:
    def isMatch(self, s, p):
        mem = {}
        def _isMatch(i, j):
            if (i, j) not in mem:
                if j == len(p):
                    result = i == len(s)
                else:
                    first_match = i < len(s) and p[j] in (s[i], '.')
                    if j + 1 < len(p) and p[j+1] == '*':
                        result = _isMatch(i, j+2) or (first_match and _isMatch(i+1, j))
                    else:
                        result = first_match and _isMatch(i+1, j+1)
                mem[i, j] = result
            return mem[i, j]

        return _isMatch(0,0)

        
if __name__ == "__main__":
    s = "baccbbcbcacacbbc"
    p = "c*.*b*c*ba*b*b*.a*"
    print(Solution().isMatch(s, p))