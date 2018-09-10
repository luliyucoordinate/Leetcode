class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        result = list()
        nums_len = len(nums)
        if nums[0] * 4 > target or nums[nums_len - 1] * 4 < target:
            return result

        if nums_len < 4:
            return result

        nums_map = {}
        for i in range(nums_len):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i+1, nums_len - 1):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                if nums[i] + nums[j] not in nums_map:
                    nums_map[nums[i] + nums[j]] = [[i, j]]
                else:
                    nums_map[nums[i] + nums[j]].append([i, j])

        for i in range(nums_len - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            for j in range(i+1, nums_len - 2):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                
                dif = target - nums[i] - nums[j]
                if dif not in nums_map:
                    continue
                else:
                    print(i, j, nums_map[dif])
                    for num in nums_map[dif]:
                        if num[1] > j:
                            result.append([nums[i], nums[j], nums[num[0]], nums[num[1]]])
        return result

    #     return self.k_sum(nums, 4, target)
    
    # # base k sum function, A is unsorted
    # def k_sum(self, A, k, goal):
    #     if k <= 0:
    #         return []
    #     elif k == 1:
    #         return [(goal)] if goal in A else []
    #     elif k == 2:
    #         results, seen = set(), set()
    #         for num in A:
    #             if num in seen:
    #                 results.add((goal - num, num))
    #             seen.add(goal - num)
    #         return list(results)
    #     else:
    #         A.sort() # lose nothing at this point by doing O(nlogn) operation
    #         return self.k_sum_helper(A, k, goal, 0)

    # # assumes A is sorted   
    # def k_sum_helper(self, A, k, goal, start):
    #     results = []
    #     if len(A) - start < k:
    #         return results
    #     i, j = start, len(A) - 1
    #     if k * A[i] > goal or k * A[j] < goal:
    #         return results
    #     if k == 2:
    #         while i < j:
    #             current_sum = A[i] + A[j]
    #             if current_sum < goal:
    #                 i += 1
    #             elif current_sum > goal:
    #                 j -= 1
    #             else:
    #                 if (i == start or A[i - 1] != A[i]) and (j == len(A) - 1 or A[j + 1] != A[j]):
    #                     results.append((A[i], A[j]))
    #                 i += 1
    #                 j -= 1
    #         return results
    #     else:
    #         for i in range(start, len(A) - k + 1):
    #             if i == start or A[i] != A[i - 1]:
    #                 for tup in self.k_sum_helper(A, k - 1, goal - A[i], i + 1):
    #                     results.append((A[i], *tup))
    #         return results

if __name__ == '__main__':
    nums = [1,0,-1,0,-2,2]
    target = 0
    print(Solution().fourSum(nums, target))