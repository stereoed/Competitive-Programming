# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    output = []
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """

        self.output = []
        def pathing(path, node):
            path += str(node.val)
            if not node.left and not node.right:
                self.output += [path]
                return
            path += "->"
            if node.left: 
                pathing(path, node.left)
            if node.right:
                pathing(path, node.right)
        pathing("", root)
        return self.output
        