class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        low = 0
        high = 2**31-1
        while low <= high:
            mid = (low+high)//2
            guess = mid*mid
            if guess == x:
                return mid
            elif guess > x:
                high = mid-1
            else:
                low = mid+1
        return high

        