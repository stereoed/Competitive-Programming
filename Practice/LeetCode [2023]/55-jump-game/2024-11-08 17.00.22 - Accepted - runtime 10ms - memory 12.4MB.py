class Solution(object):
    def canJump(self, nums):
        sums=0
        for i in nums:
            if sums < 0:
                return False

            elif i > sums:
                sums = i
            sums -= 1
        return True