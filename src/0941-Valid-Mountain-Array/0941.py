class Solution:
    def validMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        i, j, A_len = 0, len(A) - 1, len(A)
        if A_len < 3:
            return False
        while i + 1 < A_len and A[i] < A[i + 1]: 
            i += 1
        while j > 0 and A[j - 1] > A[j]: 
            j -= 1
        return 0 < i == j < A_len - 1

if __name__ == "__main__":
    A = [0,3,2,1]
    print(Solution().validMountainArray(A))