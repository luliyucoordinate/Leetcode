# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x: x.start)
        result = list()
        for item in intervals:
            if not result or result[-1].end < item.start:
                result.append(item)
            else:
                result[-1].end = max(result[-1].end, item.end)

        return result

if __name__ == "__main__":
    intervals = list(Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18))
    print(Solution().merge(intervals))
        