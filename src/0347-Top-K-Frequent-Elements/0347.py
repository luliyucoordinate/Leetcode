# class Solution:
#     def topKFrequent(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: List[int]
#         """
#         from collections import Counter
#         return [item[0] for item in Counter(nums).most_common(k)] 

class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """   
        import heapq
        count_list = dict()
        for i in nums:
            count_list[i] = count_list.get(i, 0) + 1
        
        p = list()
        result = list()
        for i in count_list.items():
            heapq.heappush(p, (-i[1], -i[0]))
            if len(p) > len(count_list) - k:
                _, val = heapq.heappop(p)
                result.append(-val)

        return result

if __name__ == '__main__':
    nums = [4,1,1,1,2,2,3]
    k = 2
    print(Solution().topKFrequent(nums, k))