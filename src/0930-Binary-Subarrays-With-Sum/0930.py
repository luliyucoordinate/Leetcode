class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        zeros, result, cnt = list(), 0, 0
        if not A:
            return result
    
        for num in A:
            if num:
                zeros.append(cnt)
                cnt = 0
            else:
                cnt += 1
        zeros.append(cnt)
        
        if S:
            for i in range(len(zeros) - S):
                result += (zeros[i] + 1)*(zeros[i+S] + 1)
            return result

        if S == 0:
            for i in range(len(zeros)):
                if zeros[i] > 0:
                    result += (zeros[i] + 1)*zeros[i]
            result //= 2
            return result

if __name__ == "__main__":
    A = [0,0,0,0,0]
    S = 0
    print(Solution().numSubarraysWithSum(A, S))