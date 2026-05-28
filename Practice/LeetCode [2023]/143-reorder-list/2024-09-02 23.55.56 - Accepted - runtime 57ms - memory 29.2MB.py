# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        # Stack, Recursion, 2-Pointer
        stack = []
        while head:
            aux = head
            head = head.next if head.next else None

            aux.next = None
            stack += [aux]
        pointer_1, pointer_2 = 0, len(stack)-1
        while pointer_1 < pointer_2:
            stack[pointer_1].next =  stack[pointer_2]
            pointer_1 += 1
            if pointer_1 == pointer_2:
                break
            stack[pointer_2].next =  stack[pointer_1]
            pointer_2 -= 1


        