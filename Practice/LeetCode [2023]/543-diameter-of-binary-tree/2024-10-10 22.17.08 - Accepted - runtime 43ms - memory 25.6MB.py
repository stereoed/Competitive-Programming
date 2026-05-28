# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    ld = 0
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.lf = 0
        def dfs(root, depth):
            if not root:
                return depth - 1

            left = dfs(root.left, depth + 1)
            right = dfs(root.right, depth + 1)
            dist = left + right - 2*depth
            if dist > self.ld:
                self.ld = dist
            return max(left, right)
        dfs(root, 0)
        return self.ld
