class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        i, n = 0, len(barcodes)
        res = [0] * n
        for k, v in collections.Counter(barcodes).most_common():
            for _ in range(v):
                res[i] = k
                i += 2
                if i >= n: 
                    i = 1
        return res