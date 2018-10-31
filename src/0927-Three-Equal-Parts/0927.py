class Solution:
    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        ones = A.count(1)
        A_len = len(A)
        if not ones:
            return [0, A_len - 1]
        if ones%3 != 0:
            return [-1, -1]
        
        step = ones//3
        p, cnt = [0]*3, 0
        for i, num in enumerate(A):
            if num == 1:
                if cnt % step == 0:
                    p[cnt//step] = i
                cnt += 1

        while p[2] < A_len and A[p[0]] == A[p[1]] and A[p[1]] == A[p[2]]:
            p[0] += 1
            p[1] += 1
            p[2] += 1

        if p[2] == A_len:
            return [p[0]-1,p[1]]

        return [-1, -1]

if __name__ == "__main__":
    A = [1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0]
    print(Solution().threeEqualParts(A))