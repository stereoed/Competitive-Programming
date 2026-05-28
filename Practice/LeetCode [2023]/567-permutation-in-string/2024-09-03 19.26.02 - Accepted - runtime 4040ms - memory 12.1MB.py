class Solution(object):
    def checkInclusion(self, s1, s2):
        s1 = sorted(s1)
        left, right = 0, len(s1)-1
        while right < len(s2):
            if sorted(s2[left:right+1]) == s1:
                return True
            right += 1
            left += 1
        return False
        