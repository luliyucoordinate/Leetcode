class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        parent = {r: region[0] for region in regions for r in region[1:]}
        n1, n2 = region1, region2
        while n1 != n2:
            n1 = parent[n1] if n1 in parent else region2
            n2 = parent[n2] if n2 in parent else region1
        return n1