class Solution(object):
    mi = 100000
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            self.mi = 0

        def d(root, depth):
            if not root:
                return
            depth += 1
            if not root.left and not root.right:
                self.mi = min(self.mi, depth)
                return
            d(root.left, depth)
            d(root.right, depth)
        d(root, 0)
        return self.mi
