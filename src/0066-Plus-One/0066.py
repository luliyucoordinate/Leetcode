class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        i = len(digits) - 1
        while i >= 0:
            if digits[i] == 9:
                digits[i] = 0
            else:
                digits[i] += 1
                return digits
            i -= 1
        
        digits[0] = 1
        digits.append(0)
        return digits
        

if __name__ == "__main__":
    digits = [0]
    print(Solution().plusOne(digits))