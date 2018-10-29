class Solution:
    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        result, cur_sum = 0, 0
        sum_dict = {0:1}
        for num in A:
            cur_sum += num
            if cur_sum - S in sum_dict:
                result += sum_dict[cur_sum - S]
            if cur_sum in sum_dict:
                sum_dict[cur_sum] += 1
            else:
                sum_dict[cur_sum] = 1
                
        return result


if __name__ == "__main__":
    A = [0,0,0,0,0]
    S = 0
    print(Solution().numSubarraysWithSum(A, S))