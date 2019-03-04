class Solution:
    def isValid(self, S: str) -> bool:
        s = list()
        for i in S:
            if i == 'c':
                if len(s) >= 2 and s[-1] == 'b' and s[-2] == 'a':
                    s.pop()
                    s.pop()
                else:
                    return False
            else:
                s.append(i)
        return len(s) == 0