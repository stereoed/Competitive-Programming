class Solution(object):
    def jump(self, nums):        
        jumps = 0
        max_reach = 0
        pos = 0

        for i in range(len(nums) - 1):
            max_reach = max(max_reach, i + nums[i])
            if i == pos:
                jumps += 1
                pos = max_reach

                if pos >= len(nums) - 1:
                    return jumps
        
        return jumps
