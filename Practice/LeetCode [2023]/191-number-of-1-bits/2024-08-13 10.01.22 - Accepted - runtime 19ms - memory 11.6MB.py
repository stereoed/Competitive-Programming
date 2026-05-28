class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        n = bin(n).replace("0b", "")
        n = re.sub('0', '', n)
        return len(n)
        