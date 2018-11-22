class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        return sum(list(a) != sorted(a) for a in zip(*A))
        
if __name__ == "__main__":
    A = ["cba","daf","ghi"]
    print(Solution().minDeletionSize(A))