class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        l = len(s)
        if numRows == 1 or l == 1:
            return s

        result = ""
        for i in range(numRows):
            j = 0
            while j*(2*numRows-2)+i < l:
                result += s[j*(2*numRows-2)+i]
                if (numRows-1)>i>0:
                    if not (j+1)*(2*numRows-2) < l:
                        if (j+1)*(2*numRows-2)-i < l:
                            result += s[(j+1) * (2 * numRows - 2) - i]
                    else:
                        result += s[(j+1) * (2 * numRows - 2) - i]
                #result += a
                j += 1
        return result