class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        A_len, i, j = len(A), 0, 1
        result = [0]*A_len
        for a in A:
            if a&1 == 0:
                result[i] = a
                i += 2
            else:
                result[j] = a
                j += 2

        return result
               

if __name__ == "__main__":
    A = [4,2,5,7]
    print(Solution().sortArrayByParityII(A))