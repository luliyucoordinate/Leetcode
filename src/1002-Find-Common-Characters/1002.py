from collections import Counter
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        return list(reduce(collections.Counter.__and__, map(collections.Counter, A)).elements())