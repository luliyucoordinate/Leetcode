class Solution:
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        counter = [[i.count('0'), i.count('1')] for i in strs]
        arr1 = sorted(counter, key=lambda s: -min(m - s[0], n - s[1]))
        arr2 = sorted(counter, key=lambda s: min(s[0], s[1]))
        return max(self._findMaxForm(arr1, m, n), self._findMaxForm(arr2, m, n))

    def _findMaxForm(self, arr, m, n):
        result = 0

        for per in arr:
            if m >= per[0] and n >= per[1]:
                result += 1
                m -= per[0]
                n -= per[1]

        return result


if __name__ == '__main__':
    strs = ["10", "0001", "111001", "1", "0"]
    m = 5
    n = 3
    print(Solution().findMaxForm(strs, m, n))