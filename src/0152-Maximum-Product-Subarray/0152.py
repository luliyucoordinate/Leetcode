class Solution:
    def maxProduct(self, A):
        """
        :type nums: List[int]
        :rtype: int
        """
        B = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i - 1] or 1
            B[i] *= B[i - 1] or 1
        return max(A + B)
        
if __name__ == "__main__":
    nums = [0,-2]
    print(Solution().maxProduct(nums))