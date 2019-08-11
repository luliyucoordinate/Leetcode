class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        data = [[username[i], timestamp[i], website[i]] for i in range(len(username))]
        data.sort()
        d = collections.defaultdict(list)
        for u, t, w in data:
            d[u].append(w)
        
        res = collections.defaultdict(set)
        for i, v in d.items():
            for j in itertools.combinations(v, 3):
                res[j].add(i)

        return sorted(res.items(), key=lambda a:(-len(a[1]), a[0]))[0][0]