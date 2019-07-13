class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        res = list()
        while 1:
            res.append(label)
            if label == 1:
                break
            label >>= 1
            label = label ^ (1 << (label.bit_length() - 1)) - 1
        return res[::-1]