# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        output = []
        queue = [root]
        queue_aux = []

        while queue:
            aux = []
            while queue:
                node = queue.pop(0)
                if node:
                    queue_aux += [node.left, node.right]
                    aux.append(node.val)

            if aux:
                output.append(aux)
            queue = queue_aux
            queue_aux = []
        return output
