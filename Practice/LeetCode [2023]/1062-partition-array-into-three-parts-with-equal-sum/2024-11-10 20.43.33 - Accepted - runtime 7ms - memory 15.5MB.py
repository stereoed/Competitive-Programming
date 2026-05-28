class Solution(object):
    def canThreePartsEqualSum(self, arr):
        total_sum = sum(arr)
        if total_sum % 3:
            return False
        partial_sum = total_sum / 3
        left = 3
        a = 0
        for num in arr:
            a += num
            if a == partial_sum:
                a = 0
                left -= 1
                
            if left == 0:
                return True
        return False