- Method 1
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result, cur_sum = 0, 0
        sum_dict = {0:1}
        for num in nums:
            cur_sum += num
            if cur_sum - k in sum_dict:
                result += sum_dict[cur_sum - k]
            if cur_sum in sum_dict:
                sum_dict[cur_sum] += 1
            else:
                sum_dict[cur_sum] = 1
                
        return result
    
- Method 2
class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        result, cur_sum = 0, 0
        sum_dict = {0:1}
        for num in nums:
            cur_sum += num
            result += sum_dict.get(cur_sum - k,0)
            sum_dict[cur_sum] = sum_dict.get(cur_sum, 0)+1
          
        return result
if __name__ == "__main__":
    nums = [1,1,1]
    k = 2
    print(Solution().subarraySum(nums, k))
