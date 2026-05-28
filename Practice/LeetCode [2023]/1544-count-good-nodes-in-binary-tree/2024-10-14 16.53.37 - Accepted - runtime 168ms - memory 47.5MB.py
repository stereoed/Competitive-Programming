
class Solution(object):
    def goodNodes(self, root):
        self.counter = 0

        def dfs(prev, root):
            if not root:
                return
            
            value = root.val
            if value >= prev:
                self.counter += 1
            else:
                value = prev
                
            dfs(value, root.left)
            dfs(value, root.right)
        
        dfs(-10**4, root)
        return self.counter