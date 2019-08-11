class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        n, m = len(str1), len(set(str2))
        if m == 26:
            return str1 == str2
        
        d = {}
        for i, c in enumerate(str1):
            if c in d:
                if d[c] != str2[i]:
                    return False
            else:
                d[c] = str2[i]
        return True