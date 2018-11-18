from heapq import heappush, heappop
class Solution:
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        heap = [(0, word1, word2)]
        visited = set()
        while heap:
            d, w1, w2 = heappop(heap)
            if (w1, w2) in visited:
                continue
            visited.add((w1, w2))    
            if w1 == w2:
                return d
            if w1 and w2 and w1[0] == w2[0]:
                heappush(heap, (d, w1[1:], w2[1:]))
            else:
                if w1: 
                    heappush(heap, (d+1, w1[1:], w2)) #delete
                if w1 and w2: 
                    heappush(heap, (d+1, w1[1:], w2[1:])) #replace
                if w2: 
                    heappush(heap, (d+1, w1, w2[1:])) #add
        
if __name__ == "__main__":
    word1 = "horse"
    word2 = "ros"
    print(Solution().minDistance(word1, word2))