class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        list_s = list(s[::-1])
        matrix = []

        while list_s:
            v = []
            for i in range(numRows):
                if not list_s:
                    break
                aux = len(matrix)%(numRows-1)
                if aux == 0 or numRows-aux-i-1==0:
                    v.append(list_s.pop())
                else:
                    v.append(' ')
            matrix.append(v)

        for i in range(len(matrix[-1]), max(len(matrix[-1]),numRows)):
            matrix[-1].append(' ')
        result = ""
        for j in range(numRows):
            for i in range(len(matrix)):
                result += matrix[i][j] if matrix[i][j] != ' ' else ''
        return result