class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        q, res, index, n = [], 0, 0, len(events)
        l, r = 100000, 0
        for i, j in events:
            l, r = min(l, i), max(r, j)

        for i in range(l, r + 1):
            while index < n and events[index][0] <= i:
                heapq.heappush(q, events[index][1])
                index += 1
                
            if not q and index == n: 
                return res
            
            while q:
                pre = heapq.heappop(q)
                if i <= pre:
                    res += 1
                    break
        return res