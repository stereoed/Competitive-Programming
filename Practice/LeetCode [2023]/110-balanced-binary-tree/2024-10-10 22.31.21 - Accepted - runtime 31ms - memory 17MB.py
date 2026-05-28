# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        self.o = True
        def depth(node):
            if not node or not self.o:
                return 0

            left_depth = depth(node.left)
            if not self.o:
                return 0

            right_depth = depth(node.right)
            if abs(left_depth - right_depth) > 1:
                self.o = False
                return 0
            
            return max(left_depth, right_depth) + 1
        depth(root)
        return self.o