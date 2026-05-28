# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        def inorder(root_a, root_b):
            flag = True
            if not root_a and not root_b:
                return True
            if (root_a and root_b):
                if root_a.val != root_b.val:
                    flag = False
                if not inorder(root_a.left, root_b.left) or not inorder(root_a.right, root_b.right):
                    flag = False
                return flag
            return False
          

        return inorder(p, q)
