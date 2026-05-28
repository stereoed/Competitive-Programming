class Solution(object):
    def matrixReshape(self, mat, r, c):
        """
        :type mat: List[List[int]]
        :type r: int
        :type c: int
        :rtype: List[List[int]]
        """
        m = len(mat)
        n = len(mat[0])
        if not (r*c == m*n):
            return mat
        output = []
        row = []
        for i in range(m):
            for j in range(n):
                row.append(mat[i][j])
                if len(row) == c:
                    output.append(row)
                    row = []
        return output