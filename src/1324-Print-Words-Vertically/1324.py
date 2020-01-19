class Solution:
    def printVertically(self, s: str) -> List[str]:
        return [''.join(a).rstrip() for a in itertools.zip_longest(*s.split(), fillvalue=' ')]