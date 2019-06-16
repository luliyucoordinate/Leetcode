from itertools import product
from functools import reduce
class Solution:
    def expand(self, S: str) -> List[str]:
        data = list()
        i, n = 0, len(S)
            
        while i < n:
            if S[i] == '{':
                tmp, j = list(), i + 1
                while j < n:
                    if S[j] == '}':
                        break
                    if S[j] != ',':
                        tmp.append(S[j])
                    j += 1
                data.append(tmp)
                i = j
            else:
                data.append([S[i]])
            i += 1
            
        res = list()
        for it in product(*data):
            res.append(reduce(lambda x, y: x + y, it))
        res.sort()
        return res