class Solution:
    def removeDuplicates(self, S: str) -> str:
        res = list()
        for c in S:
            if len(res) and res[-1] == c:
                res.pop()
            else:
                res.append(c)
        return "".join(res)