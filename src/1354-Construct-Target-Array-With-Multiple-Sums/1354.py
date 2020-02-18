class Solution:
    def isPossible(self, target: List[int]) -> bool:
        q, s = [], 0
        for i in target:
            heapq.heappush(q, -i)
            s += i

        while 1:
            pre = -heapq.heappop(q)
            s -= pre
            if pre == 1 or s == 1:
                return True
            if pre < s or pre % s == 0:
                return False
            
            pre %= s
            s += pre
            heapq.heappush(q, -pre)