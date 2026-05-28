# Definition for a binary tree node.
class TreeNode(object):
     def __init__(self, val=0, left=None, right=None):
         self.val = val
         self.left = left
         self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        # Inorder -> left, root, right
        if not root:
            return
        ls = []
        if root.left:
            ls += self.inorderTraversal(root.left)
        ls += [root.val]
        if root.right:
            ls += self.inorderTraversal(root.right)
        return ls
