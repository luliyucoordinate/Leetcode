class Solution:
    def luckyNumbers(self, A: List[List[int]]) -> List[int]:
        return list({min(row) for row in A} & {max(col) for col in zip(*A)})