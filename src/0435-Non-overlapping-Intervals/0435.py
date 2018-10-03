# Definition for an interval.
class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        intervals.sort(key=lambda x: x.start) 
        result = 0
        prev = None
        for cur in intervals:
            if not prev and prev.end > cur.start:
                result += 1
                if cur.end < prev.end:
                    prev = cur
            else:
                prev = cur
        return result
        

if __name__ == "__main__":
    intervals = [[1,2], [2,3], [3,4], [1,3]]
    print(Solution().eraseOverlapIntervals(intervals))