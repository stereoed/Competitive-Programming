class Solution(object):
    def canJump(self, nums):
        aux = 0
        for index in range(len(nums)):
            steps = nums[index]
            steps = max(steps, aux)

            if not steps and index < len(nums) - 1:
                return False

            aux = steps - 1
        return True
        