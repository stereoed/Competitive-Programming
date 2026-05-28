# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        inorderList = []
        sortedList = []

        def helper(node):
            if not node:
                return
            helper(node.left)
            inorderList.append(node.val)
            sortedList.append(node.val)
            helper(node.right)
        
        helper(root)
        sortedList.sort()
        return inorderList == sortedList and len(set(inorderList)) == len(inorderList)