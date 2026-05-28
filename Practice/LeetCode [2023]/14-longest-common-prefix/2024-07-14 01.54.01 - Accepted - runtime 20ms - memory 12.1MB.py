class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 1:
            return strs[0]
        if strs.__contains__(""):
            return ""
        shortestIndex = 0
        for i in strs:
            if len(strs[shortestIndex]) > len(i):
                shortestIndex = strs.index(i)

        prefix = strs[shortestIndex][0]
        lent = 0
        flag = True
        while flag:
            for s in strs:
                if not s[lent] == prefix[lent]:
                    flag = False
                    break
            if flag:
                lent += 1
                if lent > len(strs[shortestIndex])-1:
                    return strs[shortestIndex]
                prefix += strs[shortestIndex][lent]
        return prefix[:-1]
