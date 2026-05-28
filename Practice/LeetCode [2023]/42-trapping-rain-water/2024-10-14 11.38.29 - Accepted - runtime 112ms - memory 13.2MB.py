class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # Definicion
        o = 0
        l = len(height)
        max_height_up_to_that_point = 0
        max_height_left, max_height_right = [0] * l, [0] * l
        
        # Preprocess info
        for i in range(l):
            max_height_left[i] = max_height_up_to_that_point
            if height[i] > max_height_up_to_that_point:
                max_height_up_to_that_point = height[i]
        
        # Process
        max_height_up_to_that_point = 0
        for i in range(l - 1, -1, -1):
            a = height[i]
            o += max(0, min(max_height_left[i], max_height_up_to_that_point) - a)
            if a > max_height_up_to_that_point:
                max_height_up_to_that_point = a
        
        # Output
        return o
            