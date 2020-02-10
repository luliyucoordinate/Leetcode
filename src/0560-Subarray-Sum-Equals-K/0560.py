class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res, cur = 0, 0
        sum_dict = collections.defaultdict(int)
        sum_dict[0] = 1
        
        for num in nums:
            cur += num
            res += sum_dict[cur - k]
            sum_dict[cur] += 1
        return res

if __name__ == "__main__":
    nums = [1,1,1]
    k = 2
    print(Solution().subarraySum(nums, k))