class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        res, p_len = list(), len(pattern)
        for q in queries:
            p, i, q_len = 0, 0, len(q)
            while i < q_len:
                if p < p_len and q[i] == pattern[p]:
                    p += 1
                elif q[i].isupper():
                    break
                i += 1
            res.append(i == len(q) and p == p_len)
        return res