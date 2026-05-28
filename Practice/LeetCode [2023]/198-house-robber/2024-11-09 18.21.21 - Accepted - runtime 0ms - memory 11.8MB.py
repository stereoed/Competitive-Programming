class Solution(object):
    def rob(self, nums):
        dp = {-3: 0, -2: 0, -1: 0, 0: nums[0]}
        def dipro(pointer):
            if pointer in dp:
                return dp[pointer]

            dp[pointer] = nums[pointer] + max(dipro(pointer - 2), dipro(pointer - 3))
            return dp[pointer]
        return max(dipro(len(nums)-1), dipro(len(nums)-2))
        