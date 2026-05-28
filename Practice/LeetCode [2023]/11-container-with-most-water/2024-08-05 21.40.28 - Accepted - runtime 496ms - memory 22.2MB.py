class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        right = len(height)-1
        m = 0
        left = 0
        while left != right:
            if height[left] < height[right]:
                m = max(m, (right-left)*height[left])
                left += 1
            else:
                m = max(m, (right-left)*height[right])
                right -= 1
        return m
                
        