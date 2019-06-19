from collections import defaultdict
class Solution:
    def largestValsFromLabels(self, values: List[int], labels: List[int], num_wanted: int, use_limit: int) -> int:
        n, data = len(values), list()
        for i in range(n):
            data.append([values[i], labels[i]])
        data.sort(reverse=True)
        
        cnts, res = defaultdict(int), 0
        for i in range(n):
            if num_wanted == 0:
                break
            if cnts[data[i][1]] < use_limit:
                res += data[i][0]
                cnts[data[i][1]] += 1
                num_wanted -= 1
        return res