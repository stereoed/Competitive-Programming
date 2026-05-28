class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = 0
        dic = {}
        for n in s:
            if n in dic:
                dic[n] += 1
            else:
                dic[n] = 1

        print(dic)
        flag = False
        for d in dic:
            if not flag and dic[d]%2:
                l += dic[d]
                flag = True
            else:
                l += dic[d] // 2 * 2
        return l
