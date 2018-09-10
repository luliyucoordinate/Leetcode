class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        record, result = {}, []
        for num in nums1:
            record[num] = record.get(num, 0) + 1
                
        for num in nums2:
            if num in record and record[num]:
                result.append(num)
                record[num] -= 1
        return result



if __name__ == "__main__":
    nums1 = [1, 2, 2, 1]
    nums2 = [2, 2]
    print(Solution().intersect(nums1, nums2))