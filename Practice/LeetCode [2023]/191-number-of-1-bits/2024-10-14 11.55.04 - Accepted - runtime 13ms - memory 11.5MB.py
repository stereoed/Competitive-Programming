class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return len(re.sub('[0b,0]', '', bin(n)))
        