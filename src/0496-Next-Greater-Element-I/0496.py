class Solution:
    def nextGreaterElement(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dic , stack = dict(), list()
        for n in nums2:
            while stack and stack[-1] < n:
                dic[stack.pop()] = n
            stack.append(n)
        return [dic.get(i , -1) for i in nums1]
