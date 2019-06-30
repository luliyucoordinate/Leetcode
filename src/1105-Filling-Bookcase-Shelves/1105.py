class Solution:
    def minHeightShelves(self, books: List[List[int]], shelf_width: int) -> int:
        n = len(books)
        mem = [float("inf")] * (n + 1)
        mem[0] = 0
        for i in range(1, n + 1):
            w, h = 0, 0
            for j in range(i-1, -1, -1):
                w += books[j][0]
                h = max(h, books[j][1])
                if w > shelf_width:
                    break
                mem[i] = min(mem[i], mem[j] + h)
        return mem[-1]