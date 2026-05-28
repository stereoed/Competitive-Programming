# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if not root:
            return False

        def dfs(pointer, s, targetSum):
            s += pointer.val
            if not pointer.left and not pointer.right:
                if s == targetSum:
                    return True
            if pointer.left:
                if dfs(pointer.left, s, targetSum):
                    return True
            if pointer.right: 
                if dfs(pointer.right, s, targetSum):
                    return True
            return False
        return dfs(root, 0, targetSum)