class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m, n = len(nums1), len(nums2)
        mid = (m+n+1)//2
        if m > n:
            nums1, nums2, m, n = nums2, nums1, n, m

        l, r = 0, m
        while l <= r:
            i = (l + r)//2
            j = mid - i
            if i < m and nums2[j-1] > nums1[i]:
                l = i + 1
            elif i > 0 and nums2[j] < nums1[i - 1]:
                r = i - 1
            else:
                if i == 0:
                    max_left = nums2[j-1]
                elif j == 0:
                    max_left = nums1[i-1]
                else:
                    max_left = max(nums1[i-1], nums2[j-1])

                if (m+n)&1 == 1:
                    return max_left

                if i == m:
                    min_right = nums2[j]
                elif j == n:
                    min_right = nums1[i]
                else:
                    min_right = min(nums1[i], nums2[j])

                return (min_right + max_left) / 2


if __name__ == "__main__":
    nums1 = [1, 3]
    nums2 = [2]
    print(Solution().findMedianSortedArrays(nums1, nums2))