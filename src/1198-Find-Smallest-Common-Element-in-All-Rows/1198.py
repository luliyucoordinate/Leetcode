from functools import reduce
class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        res = reduce(operator. __and__, map(set, mat))
        return min(res) if res else -1