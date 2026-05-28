class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows = len(grid)
        columns = len(grid[0])
        perimeter = 0
        for row in range(rows):
            for column in range(columns):
                borders_with_water = 0
                if grid[row][column] == 1:
                    # Check lat
                    for delta in [-1,1]:
                        if row+delta >= rows or row+delta < 0 or grid[row+delta][column] == 0:
                            borders_with_water += 1
                        if column+delta >= columns or column+delta < 0 or grid[row][column+delta] == 0:
                            borders_with_water += 1
                perimeter += borders_with_water
        return perimeter