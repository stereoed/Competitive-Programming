class Solution(object):
    def rightSideView(self, root):
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
                output.append(aux[-1])
            
            queue = queue_aux
            queue_aux = []
        return output
