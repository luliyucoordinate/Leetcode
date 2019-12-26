class Solution:
    def maxCandies(self, status: List[int], candies: List[int], keys: List[List[int]], containedBoxes: List[List[int]], initialBoxes: List[int]) -> int:
        q, res = initialBoxes, 0
        while q:
            q_len, changed = len(q), False
            for _ in range(q_len):
                b = q.pop(0)
                if status[b]:
                    changed = True
                    res += candies[b]
                    q += containedBoxes[b]
                    for i in keys[b]:
                        status[i] = 1
                else:
                    q.append(b)

            if not changed:
                return res
        return res