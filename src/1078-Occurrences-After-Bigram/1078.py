class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        data = text.split(" ")
        pre, cur = "", ""
        
        res = list()
        for s in data:
            if pre == first and cur == second:
                res.append(s)
            pre, cur = cur, s
        return res