import itertools
class Solution:
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1, v2 = map(int, version1.split('.')), map(int, version2.split('.'))
        v1, v2 = zip(*itertools.zip_longest(v1, v2, fillvalue=0))
        return (0, 1, -1)[(v1 > v2) - (v1 < v2)]