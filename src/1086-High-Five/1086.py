from collections import defaultdict
class Solution:
    def highFive(self, items: List[List[int]]) -> List[List[int]]:
        data = defaultdict(list)
        for it in items:
            data[it[0]].append(it[1])
        
        res = list()
        for it in data.items():
            res.append([it[0], sum(sorted(it[1], reverse=True)[:5])//5])
        return res