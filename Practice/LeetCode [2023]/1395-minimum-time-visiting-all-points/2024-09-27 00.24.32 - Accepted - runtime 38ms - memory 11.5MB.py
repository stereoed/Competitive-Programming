class Solution(object):
    def minTimeToVisitAllPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        counter = 0
        starting_point = points.pop(0)
        x = starting_point[0]
        y = starting_point[1]
        
        for point in points:
            goal_x = point[0]
            goal_y = point[1]
            
            counter += max(abs(goal_x-x), abs(goal_y-y))
            
            x = goal_x
            y = goal_y
        return counter