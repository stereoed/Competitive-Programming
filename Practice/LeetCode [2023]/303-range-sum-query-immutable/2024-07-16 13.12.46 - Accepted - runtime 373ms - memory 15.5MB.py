class NumArray(object):
    numis = None
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.numis = nums

    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        return sum(self.numis[left:right+1])

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)