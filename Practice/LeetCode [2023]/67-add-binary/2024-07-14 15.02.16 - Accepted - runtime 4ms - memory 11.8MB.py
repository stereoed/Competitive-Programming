class Solution(object):
    # Binary sums 0 + 0 = 0, 0 + 1 = 1, 1 + 0 = 1, and 1 + 1 = 10.
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        # int(a,2) binary to decimal
        return bin(int(a,2) + int(b,2)).replace("0b", "") # Decimal to Binary
