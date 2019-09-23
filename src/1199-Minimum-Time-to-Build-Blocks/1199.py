import heapq
class Solution:
    def minBuildTime(self, blocks: List[int], split: int) -> int:
        heapq.heapify(blocks)
        while len(blocks) > 1:
            _, y = heapq.heappop(blocks), heapq.heappop(blocks)
            heapq.heappush(blocks, y + split)
    return blocks[0]