class Solution(object):
    mi = 100000
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
           return 0
        queue = [root] #Initialize a queue
        depth = 1
        visited = 0
        nNone = 0

        while queue:    # Creating loop to visit each node
            m = queue.pop(0)
            if not m.left and not m.right:
                return depth
            if m.left:
                queue.append(m.left)
            else:
                nNone += 1
            if m.right:
                queue.append(m.right)
            else:
                nNone += 1

            visited += 2
            if visited == 2**depth:
                nNone *= 2
                visited = nNone
                depth += 1