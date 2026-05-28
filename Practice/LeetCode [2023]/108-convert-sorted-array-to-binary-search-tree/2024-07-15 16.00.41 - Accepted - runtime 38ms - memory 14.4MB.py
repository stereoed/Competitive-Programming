# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def TreeCreator(nums):
            lastIndex = len(nums)-1
            # +- 1
            mid = lastIndex//2
            lChild = None
            rChild = None
            if mid > 0:
                lChild = TreeCreator(nums[:mid])
            if mid < lastIndex:
                rChild = TreeCreator(nums[mid+1:])
            return TreeNode(nums[mid], lChild, rChild)
        return TreeCreator(nums)