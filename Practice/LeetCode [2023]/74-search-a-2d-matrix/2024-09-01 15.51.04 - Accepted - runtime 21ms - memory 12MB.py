class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        aux = []
        for row in matrix:
            aux += row
        left, right = 0, len(aux)-1
        while left <= right:
            mid = (left + right)//2
            if aux[mid] == target:
                return True
            if aux[mid] > target:
                right = mid - 1
            else:
                left = mid + 1
        return False
