# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root, subRoot):
        # Helper function to convert tree to a string via DFS traversal
        def serialize(root):
            # Stack for DFS
            stack = [root]
            # Start output with leading delimiter to avoid "'2' is subtree of '12'" etc.
            output = ','
            while stack:
                currNode = stack.pop()
                if currNode:
                    output += str(currNode.val) + ','
                    stack.append(currNode.left)
                    stack.append(currNode.right)
                else:
                    output += '*,'
            return output
        
        tree = serialize(root)
        subTree = serialize(subRoot)
        print(tree)
        print(subTree)
        return subTree in tree