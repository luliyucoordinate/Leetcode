class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        record = {}
        for i in C:
            for j in D:
                record[i + j] = record.get(i + j, 0) + 1

        result = 0
        for i in A:
            for j in B:
                if 0 - i - j in record:
                    result += record[0 - i - j]

        return result

if __name__ == "__main__":
    A = [ 1, 2]
    B = [-2,-1]
    C = [-1, 2]
    D = [ 0, 2]
    print(Solution().fourSumCount(A, B, C, D))