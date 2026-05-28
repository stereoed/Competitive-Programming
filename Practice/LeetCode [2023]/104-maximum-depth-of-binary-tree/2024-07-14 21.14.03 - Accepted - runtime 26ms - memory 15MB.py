# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        def depth(root, cd):
            a1, a2 = 0, 0
            if root.left:
                a1 = depth(root.left, cd+1)
            if root.right:
                a2 = depth(root.right, cd+1)
            cd = max(cd,a1,a2)
            return cd
        return depth(root, 1)
        