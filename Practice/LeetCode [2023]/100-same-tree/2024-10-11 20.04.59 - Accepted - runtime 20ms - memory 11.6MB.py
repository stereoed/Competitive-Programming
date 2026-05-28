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
        def compareNodes(a, b):
            flag = True
            if a and b:
                if a.val != b.val:
                    return False

                flag = compareNodes(a.left, b.left)

                if not flag:
                    return False

                flag = compareNodes(a.right, b.right)
            elif a or b:
                return False
            return flag

        #printInorder(root)
        return compareNodes(p, q)
        