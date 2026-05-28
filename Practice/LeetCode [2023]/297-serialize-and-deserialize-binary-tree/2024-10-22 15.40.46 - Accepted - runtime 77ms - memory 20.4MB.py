class Codec:
    # Encodes a tree to a single string.
    def serialize(self, root):
        if not root:
            return ""

        queue = collections.deque([root])
        result = []

        while queue:
            node = queue.popleft()

            if node:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)
            else:
                result.append("#")

        return ",".join(result)

    # Decodes your encoded data to tree.
    def deserialize(self, data):
        print(data)
        if not data:
            return None

        values = data.split(",")
        root = TreeNode(int(values[0]))
        queue = collections.deque([root])
        i = 1

        while queue:
            node = queue.popleft()

            if values[i] != "#":
                leftNode = TreeNode(int(values[i]))
                node.left = leftNode
                queue.append(leftNode)
            i += 1

            if values[i] != "#":
                rightNode = TreeNode(int(values[i]))
                node.right = rightNode
                queue.append(rightNode)
            i += 1

        return root