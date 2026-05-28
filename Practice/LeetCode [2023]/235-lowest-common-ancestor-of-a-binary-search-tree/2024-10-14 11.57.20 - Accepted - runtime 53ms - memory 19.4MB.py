class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        smaller = min(p.val, q.val)
        greater = max(p.val, q.val)
        while True:
            if root.val < smaller:
                root = root.right
            elif root.val > greater:
                root = root.left
            else:
                return root
            