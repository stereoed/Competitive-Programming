class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        seen = set()
        s_nums = set(nums)
        max_len = 0
        for num in s_nums:
            if num in seen:
                continue

            leng = 1
            left, right = num-1, num+1
            while left in s_nums:
                leng += 1
                seen.add(left)
                left -= 1
            while right in s_nums:
                leng += 1
                seen.add(right)
                right += 1
            seen.add(num)
            max_len = max(max_len, leng)
        return max_len

    
        