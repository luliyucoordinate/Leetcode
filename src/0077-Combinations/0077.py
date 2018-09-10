import itertools
class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums = [i for i in range(1,n+1)]
        return list(itertools.combinations(nums,k))

# class Solution:
#     def combine(self, n, k):
#         """
#         :type n: int
#         :type k: int
#         :rtype: List[List[int]]
#         """
#         result = list()
#         pool = [i for i in range(1, n + 1)]
#         if k > n:
#             return
#         indices = [i for i in range(k)]
#         result.append([pool[i] for i in indices])
#         print([i for i in reversed(range(k))])
#         while True:
#             for i in reversed(range(k)):
#                 if indices[i] != i + n - k:
#                     break
#             else:
#                 return result

#             indices[i] += 1
#             for j in range(i+1, k):
#                 indices[j] = indices[j-1] + 1
#             result.append([pool[i] for i in indices])    

if __name__ == '__main__':
    n, k = 4, 2
    print(Solution().combine(n, k))

