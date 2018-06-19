class Solution:
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = list()
        for p in path:
            if p == '/' or p == '.':
                stack.append(p)

if __name__ == "__main__":
    path = "/a/./b/../../c/"
    print(Solution().simplifyPath(path))