class Solution:
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        def helper(log):
            _id, rest = log.split(" ", 1)
            return (0, rest, _id) if rest[0].isalpha() else (1,)

        return sorted(logs, key=helper)

if __name__ == "__main__":
    logs = ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
    print(Solution().reorderLogFiles(logs))