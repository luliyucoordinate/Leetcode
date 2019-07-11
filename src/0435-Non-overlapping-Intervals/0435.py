class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: x[0]) 
        result, pre = 0, None
        for cur in intervals:
            if prev and prev[1] > cur[0]:
                result += 1
                if cur[1] < prev[1]:
                    prev = cur
            else:
                prev = cur
        return result
        

if __name__ == "__main__":
    intervals = [[1,2], [2,3], [3,4], [1,3]]
    print(Solution().eraseOverlapIntervals(intervals))