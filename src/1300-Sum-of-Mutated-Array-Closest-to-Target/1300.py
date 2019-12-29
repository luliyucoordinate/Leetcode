class Solution:
    def findBestValue(self, A: List[int], target: int) -> int:
        A.sort(reverse=True)
        maxA = A[0]
        while A and target >= A[-1] * len(A):
            target -= A.pop()
        return int(target/len(A) + 0.49) if A else maxA