class Solution:
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        nums1[m:] = nums2[:n]
        all_list = nums1.copy()
        all_len = m + n

        i = 0
        j = m
        for k in range(all_len):
            if i > m - 1:
                nums1[k] = all_list[j]
                j += 1
            elif j > all_len - 1:
                nums1[k] = all_list[i]
                i += 1
            elif all_list[i] < all_list[j]:
                nums1[k] = all_list[i]
                i += 1
            else:
                nums1[k] = all_list[j]
                j += 1
        
if __name__ == "__main__":
    nums1 = [1,2,3,0,0,0]
    m = 3
    nums2 = [2,5,6]
    n = 3
    Solution().merge(nums1, m, nums2, n)
    print(nums1)