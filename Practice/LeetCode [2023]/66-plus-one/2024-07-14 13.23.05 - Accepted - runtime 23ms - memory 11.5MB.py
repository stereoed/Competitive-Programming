class Solution(object):
    # Easy solution
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        num = ""
        for i in digits:
            num += str(i)
        num = str(int(num) + 1)
        result = []
        for i in num:
            result.append(int(i))
        return result
