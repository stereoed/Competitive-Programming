class Solution(object):
    def buildTree(self, preorder, inorder):
        if not preorder:
            return None

        value = preorder.pop(0)

        index = inorder.index(value)
        left = inorder[:index]
        right = inorder[index + 1:]

        index_preorder = -1
        leftChild, rightChild = None, None
        if left:
            leftChild = self.buildTree(preorder, left)
        if right:
            rightChild = self.buildTree(preorder, right)

        root = TreeNode(value, leftChild, rightChild)
        return root

        