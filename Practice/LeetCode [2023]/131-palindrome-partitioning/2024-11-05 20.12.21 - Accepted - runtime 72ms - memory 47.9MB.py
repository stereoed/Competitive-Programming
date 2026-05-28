class Solution(object):
    def isPalindrome(self, s):
        return s == s[::-1]

    def partition(self, s):
        n = len(s)
        o = []

        def dfs(start, path):
            if start == n:
                o.append(path[:])
                return

            for index in range(start, n):
                snippet = s[start:index + 1]
                if index == start or self.isPalindrome(snippet):
                    path.append(snippet)
                    dfs(index + 1, path)
                    path.pop(-1)
        dfs(0, [])
        return o