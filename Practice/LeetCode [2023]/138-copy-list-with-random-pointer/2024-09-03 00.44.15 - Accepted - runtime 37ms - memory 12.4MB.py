"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution(object):
    def copyRandomList(self, head):
        dic = {}
        head_copy = None
        aux = head
        pointer = head_copy
        p_back = None

        while head:
            pointer = Node(head.val, head.next, None)
            dic[head] = pointer
            if not p_back:
                head = head.next
                p_back = pointer
                head_copy = p_back
                continue
            p_back.next = pointer
            p_back = p_back.next
            head = head.next
        
        pointer = head_copy
        while aux:
            if aux.random:
                dic[aux].random = dic[aux.random]
            aux = aux.next
        return head_copy
            

        