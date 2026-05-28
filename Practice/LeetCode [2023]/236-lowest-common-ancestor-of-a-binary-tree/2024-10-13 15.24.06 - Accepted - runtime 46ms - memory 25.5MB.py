# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        self.o = None
        self.p = p.val
        self.q = q.val


        print(self.p, self.q)
        def dfs(root):
            if not root:
                return 0

            has_left = dfs(root.left)
            if has_left == -1:
                return -1

            has_right = dfs(root.right)
            if has_right == -1:
                return -1
            
            current = (root.val == self.p or root.val == self.q)
            if has_left == 1 and has_right == 1:
                self.o = root
                return -1
            elif has_left == 1 or has_right == 1:
                if current:
                    self.o = root
                    return -1
                return 1
            elif current:
                return 1
        dfs(root)
        return self.o