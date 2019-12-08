class Solution:
    def groupThePeople(self, a: List[int]) -> List[List[int]]:
        data = collections.defaultdict(list)
        for i, v in enumerate(a):
            data[v].append(i)
        return [v[i:i+k] for k, v in data.items() for i in range(0, len(v), k)]