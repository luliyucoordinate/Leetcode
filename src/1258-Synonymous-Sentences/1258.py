class Solution:
    def generateSentences(self, synonyms: List[List[str]], text: str) -> List[str]:
        parent = collections.defaultdict(str)
        data = collections.defaultdict(list)
        
        def find(x):
            if x not in parent:
                parent[x] = x
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        
        for p, q in synonyms:
            x, y = find(p), find(q)
            if x != y:
                parent[x] = y
        for k in parent:
            data[find(k)].append(k)
            
        res = [[]]
        for w in text.split(" "):
            res = [it + [v] for it in res for v in data[find(w)] or [w]]
        return sorted([" ".join(it) for it in res])