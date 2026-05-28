# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def printInorder(root):
            if root:
                root.left, root.right = root.right, root.left
                # First recur on left child
                printInorder(root.left)
        
                # now recur on right child
                printInorder(root.right)

        printInorder(root)
        return root


        